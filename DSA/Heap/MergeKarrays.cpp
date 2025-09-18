#include <bits/stdc++.h>
struct Node
{
    int data;
    int i;
    int j;

    Node(int data, int row, int col) : data(data), i(row), j(col) {}
};

class Compare
{
    public:
    bool operator()(Node o1, Node o2){
        return o1.data > o2.data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue< Node, vector<Node>, Compare > pq;

    for(int i = 0; i<k; i++)
    {
        Node demo(kArrays[i][0], i, 0);
        pq.push(demo);
    }
    vector<int> ans;
    
    while(pq.size()>0)
    {
        Node demo = pq.top();
        ans.push_back(demo.data);
        pq.pop();

        int j = demo.j;
        int i = demo.i;
        if(j+1 < kArrays[i].size())
        {
            demo.data = kArrays[i][j+1];
            demo.j = (j)+1;
            pq.push(demo);
        }
    }

    return ans;
}
