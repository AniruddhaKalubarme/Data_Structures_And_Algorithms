void dfs(vector<vector<int>> &adj, map<int, bool> &visited, vector<int> &component, int val)
{
    component.push_back(val);

    for(auto i:adj[val])
    {
        if(visited[i] == false)
        {
            visited[val] = true;
            dfs(adj, visited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(int i = 0; i<E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans(V);
    map<int, bool> visited;

    for(int i = 0; i<V; i++)
    {
        if(visited[i] == false)
        {
            vector<int> component;
            visited[i] = true;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}