/*Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

*/

class Solution {
public:
    int countVowelPermutation(int n) {
        map<char,long long> mp1,mp2;
        mp1['a']=1;
        mp1['e']=1;
        mp1['i']=1;
        mp1['o']=1;
        mp1['u']=1;
        long long mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            mp2['a']=(mp1['e']+mp1['i']+mp1['u'])%mod;
            mp2['e']=(mp1['a']+mp1['i'])%mod;
            mp2['i']=(mp1['e']+mp1['o'])%mod;
            mp2['o']=(mp1['i']);
            mp2['u']=(mp1['o']+mp1['i'])%mod;
            mp1=mp2;
        }
        long long ans=0;
        for(auto it:mp1)
        {
            ans=(ans+it.second)%mod;
        }
        return ans;
        
    }
};
