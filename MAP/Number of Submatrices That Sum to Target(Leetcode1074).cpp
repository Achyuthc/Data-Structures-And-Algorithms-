/*Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 */

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        long long ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            vector<long long> v(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++)
            {
                long long sum=0;
                unordered_map<long long,int> mp;
                for(int k=0;k<matrix[0].size();k++)
                {
                    
                    v[k]+=(long long)matrix[j][k];
                    //cout<<v[k]<<" ";
                    sum+=v[k];
                    if(sum==target)
                        ans++;
                    if(mp.find(sum-target)!=mp.end())
                        ans+=mp[sum-target];
                    if(mp.find(sum)!=mp.end())
                        mp[sum]=mp[sum]+1;
                    else
                        mp[sum]=1;
                    //cout<<sum-target<<" ";
                    
                    
                }
                //cout<<'\n';
            }
        }
        return ans;
        
    }
};
