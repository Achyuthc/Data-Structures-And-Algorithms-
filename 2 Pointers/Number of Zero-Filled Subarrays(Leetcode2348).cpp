/*Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
		//store the answer
        long long ans=0;
		//to check zeros
        int left=0,right=0;
        while(right<nums.size())
        {
			//if left element is not zero then increment left
            while(left<right&&nums[left]!=0)
                left++;
			//if right element is 0 we can right-left+1 arrays ending at right 
            if(nums[right]==0)
                ans+=right-left+1;
            else
                left=right;
            right++;
        }
        return ans;
        
    }
};
