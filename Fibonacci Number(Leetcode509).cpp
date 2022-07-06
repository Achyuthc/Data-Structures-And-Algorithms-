/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).*/

class Solution {
public:
    int fib(int n) {
        
        if(n==0||n==1)
            return n;
        int x,ans=1,prev=0;
        for(int i=2;i<=n;i++)
        {
            x=ans;
            ans=ans+prev;
            prev=x;
        }
        return ans;
    }
};
