/*You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 */

sort the so that we can count all the integers.
build the {element,frequency} vector and sort based on frequency
choose the integers with highest frequency to lowest frequency untill the cnt becomes greater than size/2.
class Solution {
public:
    static bool comparator(pair<int,int> &p1,pair<int,int> &p2)
    {
        return p1.second>p2.second;
    }
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<pair<int,int>> elementAndFrequency;
        
        for(int i=0;i<arr.size();i++)
        {
            if(elementAndFrequency.empty()||arr[i-1]!=arr[i])
            {
                elementAndFrequency.push_back({arr[i],1});
            }
            else
            {
                elementAndFrequency.back().second++;
            }
        }
        
        sort(elementAndFrequency.begin(),elementAndFrequency.end(),comparator);
        
        int cnt=0,i;
        for(i=0;i<elementAndFrequency.size()&&cnt<(arr.size()/2);i++)
        {
            cnt+=elementAndFrequency[i].second;
        }
        
        return i;
    }
};


