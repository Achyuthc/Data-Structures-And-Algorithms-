


/*Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 */


class Solution {
public:
    long long dp[1001];
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]%arr[j]==0&&mp.find(arr[i]/arr[j])!=mp.end())
                {
                    dp[i]=(dp[i]+dp[j]*dp[mp[arr[i]/arr[j]]])%mod;
                }
            }
            ans=(ans+dp[i])%mod;
        }
        
        return ans;
        
    }
};

