/*Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==((1<<31)))
            return false;
        
        if(n<=0||n==2)
            return false;
        if(n==1)
            return true;
        int cnt=0,setBits=0;
        while(n>=1)
        {
            if(n&1)
                setBits++;
            else
                cnt++;
            n/=2;
        }
        return cnt%2==0&&setBits==1;
    }
};
