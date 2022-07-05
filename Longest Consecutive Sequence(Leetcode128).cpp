
/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lengthOfLCS=0,tempLCS=0;
        unordered_map<int,bool> numberExists;
        for(int &num:nums)
            numberExists[num]=true;
        
        for(int i=0;i<nums.size();i++)
        {
            if(numberExists[nums[i]+1])
                continue;
            int num=nums[i];
            tempLCS=0;
            while(numberExists[num])
            {
                tempLCS++;
                num--;
            }  
            lengthOfLCS=max(lengthOfLCS,tempLCS);
            
        }
        return lengthOfLCS;
    }
};
