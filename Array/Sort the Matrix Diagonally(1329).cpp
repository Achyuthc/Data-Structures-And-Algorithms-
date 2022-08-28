/*A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int j=0;j<n;j++)
        {
            int row=0,col=j;
            vector<int> v;
            while(row<m&&col<n)
            {
                v.push_back(mat[row++][col++]);
            }
            sort(v.begin(),v.end());
            row=0,col=j;
            int index=0;
            while(row<m&&col<n)
            {
                mat[row++][col++]=v[index++];
            }
        }
        for(int i=1;i<m;i++)
        {
            int row=i,col=0;
            vector<int> v;
            while(row<m&&col<n)
            {
                v.push_back(mat[row++][col++]);
            }
            sort(v.begin(),v.end());
            row=i,col=0;
            int index=0;
            while(row<m&&col<n)
            {
                mat[row++][col++]=v[index++];
            }
        }
        
        return mat;
        
    }
};
