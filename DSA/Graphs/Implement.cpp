#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<class T>
class graph
{
    public:
    unordered_map<T, list<T>> adj;

    void Insert(T u, T v, bool Directed)
    {
        adj[u].push_back(v);

        if(!Directed)
            adj[v].push_back(u);
    }

    void Display()
    {
        for(auto i: adj)
        {
            cout<<i.first<<" -> ";
            for(auto j: i.second)
            {
                cout<<j<<" ";
            }

            cout<<endl;
        }
    }
};

int main()
{
    graph<int> obj;
    int n;
    cout<<"Enter the number of Nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the number of Edges: ";
    cin>>m;

    for(int i = 0; i<m; i++)
    {
        int u, v;
        cout<<"Enter the Edges: ";
        cin>>u>>v;

        obj.Insert(u, v, false);
    }

    obj.Display();
    return 0;
}