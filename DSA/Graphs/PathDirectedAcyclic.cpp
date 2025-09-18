#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

class Graph
{
    int Vertex;
    unordered_map<int, list<pair<int, int>>> adj;
    vector<int> dist;
    stack<int> s;
    vector<bool> visited;
    public:

    Graph(int v) : Vertex(v), dist(v, INT_MAX), visited(v){}

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    void printAdj()
    {
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<"{"<<j.first<<", "<<j.second<<"} -> ";
            }
            cout<<endl;
        }
    }

    void dfs(int val)
    {
        visited[val] = true;
        for(auto neighbor:adj[val])
        {
            if(visited[neighbor.first] == false)
            {
                dfs(neighbor.first);
            }
        }
        s.push(val);
    }

    void printTopo()
    {
        while(!s.empty())
        {
            cout<<s.top()<<" -> ";
            s.pop();
        }
        cout<<endl;
    }

    void FindShortestPath(int source)
    {
        dist[source] = 0;

        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            
            if(dist[top]!=INT_MAX)
            {
                cout<<"top is: "<<top<<endl;
                for(auto j:adj[top])
                {
                    if(dist[j.first] > (dist[top]+j.second))
                        dist[j.first] = dist[top]+j.second;
                }
            }
        }
    }

    void printDist()
    {
        for(auto i:dist)
            cout<<i<<" -> ";
        cout<<endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,3,6);
    g.addEdge(1,2,2);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    // g.printAdj();
    g.dfs(0);
    // g.printTopo();

    int source = 1;
    g.FindShortestPath(source);
    g.printDist();
    return 0;
}