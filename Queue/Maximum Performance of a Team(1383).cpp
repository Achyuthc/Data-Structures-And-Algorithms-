/*You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 */

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.begin(),v.end());
        int i=n-1;
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0,mod=1e9+7,ans=0;
        while(i>=0)
        {
            pq.push(v[i].second);
            sum+=v[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            
            ans=max(ans,sum*v[i].first);
            i--;
        }
        return ans%mod;
    }
};
