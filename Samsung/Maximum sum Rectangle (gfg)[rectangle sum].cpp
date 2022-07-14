/*Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.*/


class Solution {
  public:
    int helper(int total[],int C)
    {
        int maxsum=INT_MIN;
        int cursum=0;
        for(int i=0;i<C;i++)
        {
            cursum+=total[i];
            maxsum=max(cursum,maxsum);
            if(cursum<0)
            {
                cursum=0;
            }
        }
        return maxsum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> m) {
        // code here
        int ans=INT_MIN;
         for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
               ans=max(ans,m[i][j]); 
            }
        }
        for(int i=0;i<R;i++)
        {
            int total[C]={0};
            for(int r=i;r<R;r++)
            {
                
                for(int c=0;c<C;c++)
                {
                    total[c]+=m[r][c];
                }
               ans=max(ans,helper(total,C));  
            }
           
        }
       
        
            
        return ans;
    }
};
