/*You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.*/


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        int currentScore;
        for(int i=1;i<nums.size();i++)
        {
            currentScore=nums[dq.front()]+nums[i];
            while(!dq.empty()&&nums[dq.back()]<=currentScore)
            {
                dq.pop_back();
            }
            dq.push_back(i);
            nums[i]=currentScore;
            //cout<<dq.front()<<" "<<i-k<<" "<<nums[i]<<"\n";
            if(i-k==dq.front())
                dq.pop_front();
            
            //cout<<nums[i]<<" ";
        }
        return nums[nums.size()-1];
    }
};
