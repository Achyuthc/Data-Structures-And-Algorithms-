/*Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //for columns

        for(int j=0;j<matrix[0].size();j++)
        {
            int row=0,column=j;
            int number=matrix[row][column];
            while(row<matrix.size()&&column<matrix[0].size())
            {
                if(number!=matrix[row][column])
                    return false;
                row++;
                column++;
            }
        }

        for(int j=0;j<matrix.size();j++)
        {
            int row=j,column=0;
            int number=matrix[row][column];
            while(row<matrix.size()&&column<matrix[0].size())
            {
                if(number!=matrix[row][column])
                    return false;
                row++;
                column++;
            }
        }

        return true;


    }
};
