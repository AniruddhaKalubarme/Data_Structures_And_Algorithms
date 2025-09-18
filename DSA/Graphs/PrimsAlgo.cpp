#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<bool> MST(n+1, false);
    unordered_map<int, vector<pair<int , int>>> adj;

    for(int i = 0; i<m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dist[1] = 0;

    for(int i = 1; i<=n; i++)
    {
        int index = -1;
        int iMin = INT_MAX;
        for(int j = 1; j<=n; j++)
        {
            if(MST[j] == false && dist[j]<iMin)
            {
                index = j;
                iMin = dist[j]; 
            }
        }
            
        MST[index] = true;
        for(auto neighbor:adj[index])
        {
            if(!MST[neighbor.first] && dist[neighbor.first] > neighbor.second)
            {
                parent[neighbor.first] = index;
                dist[neighbor.first] = neighbor.second;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i<=n; i++)
    {
        result.push_back({{parent[i], i}, dist[i]});
    }
    return result;

}
