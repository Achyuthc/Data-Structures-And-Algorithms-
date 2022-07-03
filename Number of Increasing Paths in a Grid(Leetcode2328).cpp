/*You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.*/


class Solution {
public:
    long long dp[1002][1002];
    int dir[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
    
    long long ans,mod=1e9+7;
    
    int helper(int i,int j,vector<vector<int>> &grid)
    {
        
        if(i==0||j==0||i>grid.size()||j>grid[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        ans=1;
        for(int k=0;k<4;k++)
        {
           int x=i+dir[k][0];
           int y=j+dir[k][1];
            if(x==0||y==0||x>grid.size()||y>grid[0].size())
                continue;
            if(grid[x-1][y-1]<grid[i-1][j-1])
                ans=(ans+helper(x,y,grid))%mod;
        }
        
        dp[i][j]=ans;
        return ans;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        long long finalAnswer=0;
        for(int i=1;i<=grid.size();i++)
        {
            for(int j=1;j<=grid[0].size();j++)
                finalAnswer=(finalAnswer+helper(i,j,grid))%mod;
        }
        
        return finalAnswer;
        
    }
};
