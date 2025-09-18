#include<iostream>
#include<map>
#include<queue>
#include"BuildTree.cpp"
using namespace std;

vector<int> VertTrav(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, map<int, vector<int> > > Nodes;
    queue< pair< Node* , pair<int, int> > > q;
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty())
    {
        pair< Node* , pair<int, int> > temp = q.front();
        q.pop(); 

        Node* fNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        Nodes[hd][lvl].push_back(fNode->data);

        if(fNode->left)
        {
            q.push(make_pair(fNode->left, make_pair(hd-1, lvl+1)));
        }
        if(fNode->right)
        {
            q.push(make_pair(fNode->right, make_pair(hd+1, lvl+1)));
        }
    }

    for(auto i:Nodes)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}