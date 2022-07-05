
/*On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long mod=1e9+7,finalAnswer=0;
        vector<vector<int> > dp(n+1,vector<int> (forget+1,0));
        dp[1][1]=1;
        long suffixSum=0;
        for(int i=2;i<=n;i++)
        {
            suffixSum=0;
            for(int j=forget;j>=2;j--)
            {
                dp[i][j]=dp[i-1][j-1];
                dp[i][j]=(dp[i][j])%mod;
                
                if(j-1>=delay)
                suffixSum=(suffixSum+(long)dp[i-1][j-1])%mod;
            }
            dp[i][1]=suffixSum;
            
        }
        
        for(int j=1;j<=forget;j++)
            finalAnswer=(finalAnswer+(long)dp[n][j])%mod;
        return finalAnswer;
        
    }
};

