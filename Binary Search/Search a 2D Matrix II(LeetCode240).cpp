/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,column=matrix[0].size()-1;
        
        while(row>=0&&row<matrix.size()&&column>=0&&column<matrix[0].size())
        {
            if(target>matrix[row][column])
            {
                row++;
            }
            else if(target==matrix[row][column])
            {
                return true;
            }
            else
            {
                column--;
            }
        }
        
        return false;
    }
};
