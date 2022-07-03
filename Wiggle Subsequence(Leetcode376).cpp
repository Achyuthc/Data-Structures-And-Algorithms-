/*A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=0;
        vector<int> wiggleSequenceLength(nums.size()+1,0);
        
        for(int i=0;i<nums.size()-1;i++)
            nums[i]=nums[i+1]-nums[i];
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=0)
                wiggleSequenceLength[i]=1;
                
            for(int j=i-1;j>=0;j--)
            {
                if((nums[i]>0&&nums[j]<0)||(nums[i]<0&&nums[j]>0))
                {
                    wiggleSequenceLength[i]=max(wiggleSequenceLength[i],wiggleSequenceLength[j]+1);
                }
            }
            ans=max(ans,wiggleSequenceLength[i]);
        }
        
        return ans+1;
    }
};
