/*There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.*/


Solution 1:BFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

    int n = graph.size();

    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B

        

    queue<int> q; // queue, resusable for BFS    

	

    for (int i = 0; i < n; i++) {

      if (color[i]) continue; // skip already colored nodes

      

      // BFS with seed node i to color neighbors with opposite color

      color[i] = 1; // color seed i to be A (doesn't matter A or B) 

      for (q.push(i); !q.empty(); q.pop()) {

        int cur = q.front();

        for (int neighbor : graph[cur]) 

		{

          if (!color[neighbor]) // if uncolored, color with opposite color

          { color[neighbor] = -color[cur]; q.push(neighbor); } 

		  

          else if (color[neighbor] == color[cur]) 

            return false; // if already colored with same color, can't be bipartite!

        }        

      }

    }

    

    return true;

  }
        
    
};

Solution 2:DFS


class Solution {
public:
    bool dfs(int u,vector<vector<int>> &graph,int colored[])
    {
        for(int v:graph[u])
        {
            if(!colored[v])
            {
                colored[v]=-colored[u];
                if(!dfs(v,graph,colored))
                    return false;
            }
            else if(colored[v]==colored[u])
            {
                return false;
            }
                
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int numberOfNodes=graph.size();
        int colored[numberOfNodes];
        memset(colored,0,sizeof(colored));
        for(int u=0;u<numberOfNodes;u++)
        {
            if(!colored[u])
            {
                colored[u]=1;
                if(!dfs(u,graph,colored))
                    return false;
            }
                
        }
        return true;
    }
};
