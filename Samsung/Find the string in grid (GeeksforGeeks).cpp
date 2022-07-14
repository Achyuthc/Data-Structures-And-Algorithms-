/*Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be
found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, 
vertically down and 4 diagonal directions*/

https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1/?page=1&status[]=solved&company[]=Samsung&sortBy=submissions

class Solution {
public:
    int solution(vector<vector<char>>grid, string word,int l,int r)
    {
        int a[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        int c=0;
        while(c!=8)
        {
            int x=l,y=r;
            int i;
            for( i=0;i<word.size()&&x>=0&&y<grid[0].size()&&y>=0&&x<grid.size();i++)
            {
                if(word[i]!=grid[x][y])
                {
                
                    break;
                }
                x+=a[c][0];
                y+=a[c][1];
            }
            c++;
            if(i==word.size())
            return 1;
        }
        return 0;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int m=grid.size(),n=grid[0].size();
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	           
	            if(solution(grid,word,i,j))
	            {
	                 vector<int> p;
	                 p.push_back(i);
	                 p.push_back(j);
	                 ans.push_back(p);
	            }
	        }
	    }
	    return ans;
	}
};
