/*You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.*/
question:https://leetcode.com/problems/where-will-the-ball-fall/
Solution:https://leetcode.com/problems/where-will-the-ball-fall/solutions/2767515/c-solution-with-dp/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> v(m+1,vector<int> (n+1,-1));

        for(int j=0;j<n;j++)
        {
            v[m][j]=j;
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if((j+1)!=n&&grid[i][j+1]==1)
                        v[i][j]=v[i+1][j+1];
                }
                else
                {
                    if(j-1>=0&&grid[i][j-1]==-1)
                        v[i][j]=v[i+1][j-1];
                }
            }
        }
        vector<int> ans;
        
        for(int j=0;j<n;j++)
            ans.push_back(v[0][j]);
        return ans;
    }
};
