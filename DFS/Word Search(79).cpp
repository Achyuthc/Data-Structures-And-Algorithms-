/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 */


class Solution {
public:
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    bool dfs(vector<vector<char>> &board,string &word,int index,int i,int j)
    {
        if(board[i][j]!=word[index])
            return false;
        if(index+1==word.size())
            return true;
        char c=board[i][j];
        board[i][j]='.';
        for(int k=0;k<4;k++)
        {
            int x=i+dir[k][0],y=j+dir[k][1];
            if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&dfs(board,word,index+1,x,y))
                return true;
        }
        board[i][j]=c;
        return false;
    }

        
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};
