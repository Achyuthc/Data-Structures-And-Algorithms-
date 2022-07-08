/*There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:

houses[i]: is the color of the house i, and 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.*/


class Solution {
public:
    int dp[101][21][101];
    int dfs(vector<int>& houses, vector<vector<int>>& cost,int i,int target,int lastColor)
    {
        if(target<0)
            return 1000001;
        if(i==-1)
            return target==0?0:1000001;
        if(houses[i]!=0)
            return dp[i][lastColor][target]=dfs(houses,cost,i-1,target-(lastColor!=houses[i]),houses[i]);
        if(dp[i][lastColor][target]!=-1)
            return dp[i][lastColor][target];
        int ans=1000001;
        
        for(int color=1;color<=cost[i].size();color++)
        {
            ans=min(ans,cost[i][color-1]+dfs(houses,cost,i-1,target-(lastColor!=color),color));
        }
        return dp[i][lastColor][target]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        
        int ans=dfs(houses,cost,m-1,target,0);
        return ans==1000001?-1:ans;
        
    }
};
