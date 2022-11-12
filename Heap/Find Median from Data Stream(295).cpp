/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.*/


Question: https://leetcode.com/problems/find-median-from-data-stream/description/
Solution: https://leetcode.com/problems/find-median-from-data-stream/solutions/2805967/c-solution-with-descriptive-variables/


class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double,vector<double>,greater<double>>minHeap;
    int size=0;
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(maxHeap.size()<minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        size++;
    }
    
    double findMedian() {
        return size%2==1?maxHeap.top():(maxHeap.top()+minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
