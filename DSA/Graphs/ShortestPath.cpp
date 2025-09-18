void FindPath(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &ans, vector<int> &temp, int source, int dest)
{
	if(source == dest)
	{
		if(ans.size() == 0 || ans.size() > temp.size())
			ans = temp;
		return;
	}

	visited[source] = true;

	for(auto neighbour:adj[source])
	{
		if(visited[neighbour] == false)
		{
			temp.push_back(source);
			FindPath(adj, visited, ans, temp, neighbour, dest);
			temp.pop_back();
		}
	}
	
	visited[source] = false;
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int, vector<int>> adj;
	vector<bool> visited(n+1);
    for(auto i:edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
		adj[v].push_back(u);
    }

	vector<int> ans, temp;
	FindPath(adj, visited, ans, temp, s, t);

	ans.push_back(t);
	return ans;
}


// Approach-2 (BFS)
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, -1); 
    vector<bool> visited(n + 1, false);

    for (auto i : edges) {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor); 
            }
        }
    }

    vector<int> path;
    int cur = t;
    path.push_back(cur);
    while (cur != s) {
        cur = parent[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    return path;
}