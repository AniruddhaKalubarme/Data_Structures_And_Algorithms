#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<int> dist(vertices, INT_MAX);

    for(int i = 0; i<edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    set<pair<int, int>> s;
    dist[source] = 0;
    s.insert({0, source});

    while(!s.empty())
    {
        auto top = *(s.begin());
        s.erase(s.begin());

        int topNode = top.second;
        int topDist = top.first;

        for(auto neighbour:adj[topNode])
        {
            if(dist[neighbour.first] > topDist + neighbour.second)
            {
                auto record = s.find({dist[neighbour.first], neighbour.first});
                if(record != s.end())
                {
                    s.erase(record);
                }

                dist[neighbour.first] = topDist + neighbour.second;
                s.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }

    return dist;
}
