/*Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.*/


class Solution {
public:
    int dp[101][101];
    int helper(string &s, int left, int K) {
        if(left==s.size()||s.size()-left<=K)
            return 0;

        if(dp[left][K]!=-1)
            return dp[left][K];
        int k=K;

        int ans=k?helper(s,left+1,K-1):1000,c=1;

        for(int i=left+1;i<=s.size();i++)
        {
            ans=min(ans,helper(s,i,k)+1+((c>=100)?3:((c>=10)?2:(c>1)?1:0)));

            if(i==s.size())
                break;
            if(s[i]==s[left])
            c++;
            else if(--k<0)
            break;
        }
        return dp[left][K]=ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, k);
    }
};
