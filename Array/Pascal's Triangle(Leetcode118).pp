
/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:*/

class Solution {
public:
        
    vector<vector<int>> generate(int numRows) {
           vector<vector<int>> p;
            vector<int>k;
            k.push_back(1);
            int i,j, n=numRows;
        for(i=1;i<=n;i++)
        {
                vector<int>v;
                for(j=1;j<=i;j++)
                {        
                
                 if(j-1==0||j-1==i-1)
                  v.push_back(1);
                 else 
                   {
                     v.push_back(k[j-1]+k[j-2]);
                   }
                }
                k=v;
               p.push_back(v);       
                       
        }
        return p;
    }
};
