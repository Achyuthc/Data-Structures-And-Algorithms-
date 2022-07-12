/*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

*/

class Solution {
public:
    vector<int> parent,rank;
    
    int find(int x)
    {
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    
    void unionFunction(int x,int y)
    {
        int px=find(x),py=find(y);
        
        if(px==py)
            return ;
        if(rank[px]<rank[py])
            parent[px]=py;
        else 
        {
            parent[py]=px;
            rank[px]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        
        rank.resize(edges.size()+1,0);
        for(int i=0;i<=edges.size();i++)
        {
            parent[i]=i;
        }
        for(auto &edge:edges)
        {
            int px=find(edge[0]),py=find(edge[1]);
            if(px!=py)
                unionFunction(px,py);
            else
                return edge;
        }
        return {};
        
    }
};
