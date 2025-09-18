class Solution {
    public:
      
      void Solve(vector<int> &ans, vector<vector<int>> &adj, map<int, bool> &visited, int val)
      {
          queue<int> q;
          q.push(val);
          
          while(!q.empty())
          {
              int top = q.front();
              q.pop();
              
              ans.push_back(top);
              
              for(auto i:adj[top])
              {
                  if(visited[i] == false)
                  {
                      visited[i] = true;
                      q.push(i);
                  }
              }
          }
          
      }
      
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          vector<int> ans;
          map<int, bool> visited;
          
          // Disconnected Graph
          // for(int i = 0; i<adj.size(); i++)
          // {
          //     if(visited[i] == false)
          //     {
          //         visited[i] = true;
          //         Solve(ans, adj, visited, i);
          //     }
          // }
          
          visited[0] = true;
          Solve(ans, adj, visited, 0);
          return ans;
      }
  };