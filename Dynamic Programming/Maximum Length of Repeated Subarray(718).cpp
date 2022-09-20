


/*Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.*/


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(),n2=nums2.size();
        int dp[n1+2][n2+2];
        memset(dp,0,sizeof(dp));
        int maxi=0;
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(nums1[i-1]==nums2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=0;
                }
                maxi=max(maxi,dp[i][j]);
                    
            }
        }
        return maxi;
        
    }
};
