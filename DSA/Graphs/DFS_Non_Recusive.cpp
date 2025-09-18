// Not in babbars course

vector<int> dfs(vector<vector<int>>& adj) {
    stack<int> s;
    vector<int> result;
    vector<bool> visited(adj.size(), false); 

    s.push(0);

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (!visited[top]) {
            visited[top] = true;
            result.push_back(top);

            // Push neighbors in reverse for correct DFS order
            for (int i = adj[top].size() - 1; i >= 0; i--) {
                int neighbor = adj[top][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    return result;
}
