/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.*/

class Solution {
public:

    
    bool isInterleave(string s1, string s2, string s3) {
     int m=s1.size(),n=s2.size(),l=s3.size();
        bool dp[101][101];
        if(l!=m+n)
        {
            return false;
        }
        for(int i=0;i<=m;i++)
        {
           for(int j=0;j<=n;j++)
           {
               if(i==0&&j==0)
               {
                   dp[i][j]=true;
               }
               else if(i==0)
               {
                   dp[i][j]=(s2[j-1]==s3[i+j-1])&&(dp[i][j-1]);
               }
               else if(j==0)
               {
                   dp[i][j]=(s1[i-1]==s3[i+j-1])&&(dp[i-1][j]);
               }
               else
               {
                   dp[i][j]=((s2[j-1]==s3[i+j-1])&&dp[i][j-1])||((s1[i-1]==s3[i+j-1])&&dp[i-1][j]);
               }
           }
        }
        return dp[m][n];
    }
};
