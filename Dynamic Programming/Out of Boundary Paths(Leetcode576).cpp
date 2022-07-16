

/*There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells
in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
Since the answer can be very large, return it modulo 109 + 7.*/

class Solution {
public:
    int dir[4][2]={{-1,0,},{0,-1},{1,0},{0,1}};
    int dp[51][51][51];
    int mod=1e9+7;
    int helper(int i,int j,int moves,int &m,int &n)
    {
        if(i<0||j<0||j>=n||i>=m)
            return 1;
        if(moves==0)
            return 0;
        if(dp[i][j][moves]!=-1)
        {
            return dp[i][j][moves];
        }
        dp[i][j][moves]=0;
        for(int k=0;k<4;k++)
        {
            dp[i][j][moves]=(dp[i][j][moves]+helper(i+dir[k][0],j+dir[k][1],moves-1,m,n))%mod;
        }
        return dp[i][j][moves];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return helper(startRow,startColumn,maxMove,m,n);
    }
};
