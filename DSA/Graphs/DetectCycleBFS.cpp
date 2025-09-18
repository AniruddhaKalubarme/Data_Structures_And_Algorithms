#include<unordered_map>
#include<map>
#include<queue>
#include<set>
#include<iostream>
#include<vector>
using namespace std;

bool isCycle(map<int, vector<int>> &adj, map<int, bool> &visited, int val)
{
    map<int, int> parent;
    queue<int> q;
    q.push(val);
    visited[val] = true;
    parent[val] = -1;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(auto neighbour : adj[top])
        {
            if(visited[neighbour] == true && parent[top] != neighbour)
            {
                return true;
            }
            else if(visited[neighbour] == false)
            {
                visited[neighbour] = true;
                parent[neighbour] = top;
                q.push(neighbour);
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m)
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
            bool ans = isCycle(adj, visited, i);
            if(ans)
                return "Yes";
        }
    }
    
    return "No";
}


int main()
{
    vector<vector<int>> adjMat = { {0,1}, {1,2}};
    int V = 3;  // Vertexg
    int E = 2;  // Edges
    cout<<cycleDetection(adjMat, V, E)<<endl;
    return 0;
}