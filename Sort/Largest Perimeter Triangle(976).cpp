/*Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
If it is impossible to form any triangle of a non-zero area, return 0.*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--)
        {
            if(nums[i-2]+nums[i-1]>nums[i])
                return nums[i-2]+nums[i-1]+nums[i];
            
        }
        return 0;
    }
};
