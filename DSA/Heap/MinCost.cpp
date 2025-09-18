class Solution {
    public:
      // Function to return the minimum cost of connecting the ropes.
      int minCost(vector<int>& arr) {
          // code here
          priority_queue<int, vector<int>, greater<int>> pq;
          for(auto i : arr)
              pq.push(i);
          
          int ans = 0;
          while(pq.size()>1)
          {
              int a = pq.top();
              pq.pop();
              
              int b = pq.top();
              pq.pop();
              
              int add = a+b;
              ans += add;
              
              pq.push(add);
          }
          
          return ans;
      }
  };