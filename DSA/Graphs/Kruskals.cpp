#include<algorithm>

bool cmp(vector<int> &a, vector<int> &b)
{
  return a[2]<b[2];
}

void initialize(vector<int> &parent, int n)
{
  for(int i = 0; i<n; i++)
  {
    parent[i] = i;
  }
}

int findParent(int node, vector<int> &parent)
{
  if(parent[node] == node)
    return node;

  return parent[node] = findParent(parent[node], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
  u = findParent(u, parent);
  v = findParent(v, parent);

  if(rank[u] < rank[v])
  {
    parent[u] = v;
  }
  else if(rank[v] < rank[u])
  {
    parent[v] = u;
  }
  else
  {
    parent[u] = v;
    rank[v]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{

  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n), rank(n, 0);
  initialize(parent, n);

  int minWeight = 0;
  for(int i = 0; i<edges.size(); i++)
  {
    int u = findParent(edges[i][0], parent);
    int v = findParent(edges[i][1], parent);
    int w = edges[i][2];

    if(u != v)
    {
      
      minWeight += w;
      Union(u, v, parent, rank);
    }
      
  }

  // cout<<"min Weight is: "<<minWeight<<endl;

  return minWeight;
}