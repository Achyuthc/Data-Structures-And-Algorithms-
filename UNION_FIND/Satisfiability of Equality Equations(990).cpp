/*You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.*/


class Solution {
public:
    int parent[26];
    int find(int node)
    {
        if(parent[node]==node||parent[node]==-1)
            return node;
        parent[node]=find(parent[node]);
        return parent[node];
    }
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>>notEqual(26);
        
        memset(parent,-1,sizeof(parent));
        
        for(auto eq:equations)
        {
            if(eq[1]=='!')
            {
                notEqual[eq[0]-'a'].push_back(eq[3]-'a');
                notEqual[eq[3]-'a'].push_back(eq[0]-'a');
            }
            else
            {
                int u=find(eq[0]-'a'),v=find(eq[3]-'a');
                
                if(parent[u]==-1&&parent[v]==-1)
                {
                    parent[u]=u;
                    parent[v]=u;
                }
                else if(parent[u]==-1)
                {
                    parent[u]=v;
                }
                else
                {
                    parent[v]=u;
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            int u=find(i);
            for(int j=0;j<notEqual[i].size();j++)
            {
                int v=find(notEqual[i][j]);
                if(u==v)
                {
                    return false;
                }
            }
            
        }
        return true;
        
    }
};
