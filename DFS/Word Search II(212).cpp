/*Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.*/

question:https://leetcode.com/problems/word-search-ii/
solution:https://leetcode.com/problems/word-search-ii/solutions/2782079/c-solution-with-trie-and-dfs/


class Solution {
public:
    class Trie
    {
        public:
        Trie *chars[26];
        int wordExist=-1;
    };
    Trie *root=new Trie();
    vector<string> ans;
    map<int,int> mp;
    int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void add(string s,int index)
    {
        Trie *node=root;
        for(char c:s)
        {
            if(node->chars[c-'a']==NULL)
            {
                node->chars[c-'a']=new Trie();
            }
            node=node->chars[c-'a'];
        }
        node->wordExist=index;
    }

    void search(Trie *node,vector<vector<char>> &board,int i,int j)
    {
        if(node->chars[board[i][j]-'a'])
        {
            char c=board[i][j];
            board[i][j]='*';
            for(int k=0;k<4;k++)
            {
                int x=i+a[k][0],y=j+a[k][1];
                if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]!='*')
                {
                    search(node->chars[c-'a'],board,x,y);
                }
            }
            node=node->chars[c-'a'];
            if(node->wordExist!=-1)
                mp[node->wordExist]=1;
            board[i][j]=c;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            add(words[i],i);
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                search(root,board,i,j);
            }
        }
        for(auto it:mp)
        {
            ans.push_back(words[it.first]);
        }
        return ans;
    }
};
