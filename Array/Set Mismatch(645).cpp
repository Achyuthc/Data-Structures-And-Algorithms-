/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long square=0,sum=0;
        
        int a,b;

        for(int i=0;i<nums.size();i++)
        {
            square+=nums[i]*nums[i];
            sum+=nums[i];
        }
        long long realSum=(nums.size()*(nums.size()+1))/2;
        long long realSquare=(nums.size()*(nums.size()+1)*(2*nums.size()+1))/6;

        a=((realSquare-square)/(realSum-sum)+realSum-sum)/2;
        b=a-realSum+sum;

        return {b,a};
    }
};
