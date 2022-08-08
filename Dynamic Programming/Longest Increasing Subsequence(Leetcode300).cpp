/*Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> list;
        int index;
        for(int i=0;i<nums.size();i++)
        {
            if(list.empty()||list.back()<nums[i])
            {
                list.push_back(nums[i]);
            }
            else
            {
                index=lower_bound(list.begin(),list.end(),nums[i])-list.begin();
                list[index]=nums[i];
            }
            //cout<<list.size()<<" ";
        }
        return list.size();
        
        
    }
};
