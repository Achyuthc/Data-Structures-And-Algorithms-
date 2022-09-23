/*Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.*/


class Solution {
public:
    int concatenatedBinary(int n) {
        long long  placeValue=1,ans=0,mod=1e9+7;
        for(int j=n;j>=1;j--)
        {
            int i=j;
            while(i>0)
            {
                ans=(ans+(i%2*placeValue))%mod;
                placeValue=(placeValue*2)%mod;
                i=i/2;
            }
        }
        return ans;
    }
};
