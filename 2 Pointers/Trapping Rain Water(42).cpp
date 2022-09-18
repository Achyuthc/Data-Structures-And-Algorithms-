
/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 */
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMaxi=0,rightMaxi=0;
        int left=0,right=height.size()-1;
        int trappedWater=0;
        while(left<=right)
        {
            if(leftMaxi<=rightMaxi)
            {
                if(min(leftMaxi,rightMaxi)>height[left])
                {
                    trappedWater+=min(leftMaxi,rightMaxi)-height[left];
                }
                leftMaxi=max(leftMaxi,height[left]);
                left++;
            }
            else
            {
                if(min(leftMaxi,rightMaxi)>height[right])
                {
                    trappedWater+=min(leftMaxi,rightMaxi)-height[right];
                }
                rightMaxi=max(rightMaxi,height[right]);
                right--;
            }
        }
        
        return trappedWater;
        
    }
};


