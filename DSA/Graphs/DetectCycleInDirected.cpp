#include<unordered_map>
#include<map>
#include<queue>
#include<set>
#include<vector>

bool isCycle(map<int, vector<int>> &adj, map<int, bool> &visited, int val, map<int, bool> &call)
{
    for(auto neighbour : adj[val])
    {
        if(visited[neighbour] == false)
        {
            visited[neighbour] = true;
            call[neighbour] = true;

            bool ans = isCycle(adj, visited, neighbour, call);
            if(ans)
                return true;
            call[neighbour] = false;
        }
        else if(call[neighbour] == true)
            return true;
    }

    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    map<int, bool> visited;
    map<int, bool> call;
    map<int, vector<int>> adj;
    int ans = 0;
    for(auto i:edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
    }
    
    for(int i = 1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            call[i] = true;
            ans = isCycle(adj, visited, i, call);
            call[i] = false;
            if(ans)
              break;
        }
    }
    
    return ans;
}