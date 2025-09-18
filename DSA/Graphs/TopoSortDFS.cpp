#include <bits/stdc++.h> 

void TopoSort(unordered_map<int, vector<int>> &adj, vector<bool> &visited, stack<int> &s, int val)
{
    for(auto neighbour:adj[val])
    {
        if(visited[neighbour] == false)
        {
            visited[neighbour] = true;
            TopoSort(adj, visited, s, neighbour);
            s.push(neighbour);
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<bool> visited(v);
    unordered_map<int, vector<int>> adj;
    stack<int> s;

    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    for(int i = 0; i<v; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            TopoSort(adj, visited, s, i);
            s.push(i);
        }
    }

    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
