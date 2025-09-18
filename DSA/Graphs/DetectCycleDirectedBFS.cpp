#include<unordered_map>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include <bits/stdc++.h> 

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> indegree(n+1);
    unordered_map<int, vector<int>> adj;
    queue<int> q;

    for(auto i:edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
    }

    for(auto i:adj)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    int iCnt = 0;
    for(int i = 1; i<=n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        iCnt++;

        for(auto neighbour:adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return !(iCnt == n);
}