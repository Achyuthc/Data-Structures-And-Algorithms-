/*Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.*/

https://leetcode.com/problems/continuous-subarray-sum/solutions/2746849/c-solution-with-remainder-with-k-in-map/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;


        int prefixSum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            if(mp.find(prefixSum%k)!=mp.end()&&(i-mp[prefixSum%k]>1))
                return true;
            if(mp.find(prefixSum%k)==mp.end())
                mp[prefixSum%k]=i;
        }
        return false;
    }
};
