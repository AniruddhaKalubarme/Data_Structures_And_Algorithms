#include<unordered_map>
#include<map>
#include<queue>
#include<set>
#include<vector>

bool isCycle(map<int, vector<int>> &adj, map<int, bool> &visited, int val, int parent)
{
    for(auto neighbour:adj[val])
    {
        if(visited[neighbour] == false)
        {
            visited[neighbour] = true;
            bool ans = isCycle(adj, visited, neighbour, val);
            if(ans)
                return true;
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    map<int, bool> visited;
    map<int, vector<int>> adj;

    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            bool ans = isCycle(adj, visited, i, -1);

            if(ans)
                return "Yes";
        }
    }
    
    return "No";
}
