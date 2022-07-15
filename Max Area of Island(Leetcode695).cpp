/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.*/

class Solution {
public:
    int m,n;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int x,int y)
    {
        return x>=0&&x<m&&y>=0&&y<n;
    }
    void dfs(int i,int j,vector<vector<int>>&grid,int &tempAns)
    {
        grid[i][j]=0;
        tempAns++;
        for(int k=0;k<4;k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(isValid(x,y)&&grid[x][y]==1)
            {
                dfs(x,y,grid,tempAns);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int tempAns;
        int Answer=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                tempAns=0;
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,tempAns);
                }
                Answer=max(tempAns,Answer);
            }
        }
        return Answer;
        
    }
};
