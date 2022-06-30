


/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.*/

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {

        int size = nums.size();
        if (size == 1)
            return 0;
        sort(nums.begin(), nums.end());

        vector<long long> suffixSum(size + 1);
        suffixSum[size] = 0;
        long long ans = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            ans += abs(nums[i]);
            suffixSum[i] = nums[i] + suffixSum[i + 1];
        }

        long long prefixSum = 0;

        for (int i = 0; i < size; i++)
        {
            prefixSum += nums[i];
            ans = min(ans, abs(((long long)i + 1) * nums[i] - prefixSum + suffixSum[i + 1] - ((long long)size - (i + 1)) * nums[i]));
        }

        return ans;
    }
};
