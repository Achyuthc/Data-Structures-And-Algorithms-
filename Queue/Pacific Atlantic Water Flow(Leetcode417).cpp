/*There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 */

Algorithm

take a queue and add all the boundary cells into the queue by metioning the atlantic or pacific it can reach pacific ->1 and atlantic->2.
keep on adding the cells with currentCell Height>= olderCell Height.
keep track of vis array if we can reach specific ocean before then no need add agian into the queue.
when ever we see vis[x][y]==3 then we can reach pecific and atlantic,add cells into final answer then return ans.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int vis[201][201],m=heights.size(),n=heights[0].size(),dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>> ans;
        queue<pair<int,int>> q;
        memset(vis,0,sizeof(vis));
        
        for(int j=0;j<n;j++)
        {
            q.push({0*201+j,1});
            q.push({(m-1)*201+j,2});
            vis[0][j]=vis[0][j]|1;
            vis[m-1][j]=vis[m-1][j]|2;
        }
        
        for(int i=0;i<m;i++)
        {
            q.push({i*201,1});
            q.push({i*201+n-1,2});
            vis[i][0]=vis[i][0]|1;
            vis[i][n-1]=vis[i][n-1]|2;
        }
        
        while(!q.empty())
        {
            int node=q.front().first,ocean=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=node/201+dir[i][0],y=node%201+dir[i][1];
                if(x>=0&&x<m&&y>=0&&y<n&&!(vis[x][y]&ocean)&&heights[node/201][node%201]<=heights[x][y])
                {
                    q.push({x*201+y,ocean});
                    vis[x][y]=vis[x][y]|ocean;
                }
            }
            
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(vis[i][j]==3)
                    ans.push_back({i,j});

        return ans;
    }
};
