
/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.*/

https://leetcode.com/problems/find-median-from-data-stream/


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxhp;
    priority_queue<int,vector<int>,greater<int>>minhp;
    int n=0;
  
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxhp.size()<minhp.size())
        {
            maxhp.push(minhp.top());
            minhp.pop();
        }
       
    }
    
    //Function to return Median.
    double getMedian()
    {
        
       if(n%2==0)
       {
           return ((double)maxhp.top()+(double)minhp.top())/(double)2;
       }
       else
       {
           return (double)maxhp.top();
       }
    }
    MedianFinder() {
        n=0;
    }
    
    void addNum(int x) {
        maxhp.push(x);
        minhp.push(maxhp.top());
        maxhp.pop();
        n++;
        balanceHeaps();
        
    }
    
    double findMedian() {
        if(n%2==0)
       {
           return ((double)maxhp.top()+(double)minhp.top())/(double)2;
       }
       else
       {
           return (double)maxhp.top();
       }
    }
};
