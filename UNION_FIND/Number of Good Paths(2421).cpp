/*There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path*/

class Solution {
public:
    vector<int> parent;
    vector<int> count,maxElement;
    int find(int node)
    {
        if(parent[node]==node)
            return node;
        parent[node]=find(parent[node]);
        return parent[node];
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](const vector<int>& a,vector<int>& b)
 			 {
 				 int m = max(vals[a[0]],vals[a[1]]);
 				 int n = max(vals[b[0]],vals[b[1]]);
 				 return m<n;
 			 });
        
        for(int i=0;i<vals.size();i++)
        {
            parent.push_back(i);
            count.push_back(1);
            maxElement.push_back(vals[i]);
        }
        
        int ans=vals.size();
        
        for(auto &e:edges)
        {
            int a=find(e[0]);
            int b=find(e[1]);
            
            if(maxElement[a]==maxElement[b])
            {
                ans+=count[a]*count[b];
                count[a]+=count[b];
                parent[b]=a;
                
            }
            else
            {
                if(maxElement[a]<maxElement[b])
                {
                    parent[a]=b;
                }
                else
                {
                    parent[b]=a;
                }
            }
        }
        
        return ans;
        
        
    }
};
