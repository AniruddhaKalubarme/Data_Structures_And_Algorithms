#include<iostream>
#include<queue>
#include<vector>
#include<BuildTree.cpp>
using namespace std;


vector<int> TopView(Node *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> tNode;
    queue<pair<Node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* fNode = temp.first;
        int hd = temp.second;

// Comment below condition for bottom View
        if(tNode.find(hd) == tNode.end())
            tNode[hd] = fNode->data;

        if(fNode->left)
            q.push(make_pair(fNode->left, hd-1));

        if(fNode->right)
            q.push(make_pair(fNode->right, hd+1));
    }

    for(auto i : tNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

void LeftView(NODE* root, vector<int> &ans, int lvl)
{
    if(root == NULL)
        return;

    if(lvl == ans.size())
        ans.push_back(root->data);
    
    // for right View just call the root->right functino first
    LeftView(root->left, ans, lvl+1);
    LeftView(root->right, ans, lvl+1);
}

int main()
{

    return 0;
}