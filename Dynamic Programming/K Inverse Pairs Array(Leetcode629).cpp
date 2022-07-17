/*For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

 */

class Solution {
public:
    int dp[1001][1001];
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=1;
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                if(j-i>=0)
                    dp[i][j]=(dp[i][j]-dp[i-1][j-i]+mod)%mod;
            }
        }
        //cout<<dp[n][k]<<" ";
        return (dp[n][k]);
        
        
    }
}; 
