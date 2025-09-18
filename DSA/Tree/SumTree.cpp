#include<iostream>
#include "BuildTree.cpp"
using namespace std;

pair<bool, int> SumTree(Node *root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    if(root -> left == NULL && root -> right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    
    pair<bool, int> left = SumTree(root->left);
    pair<bool, int> right = SumTree(root->right);

    pair<bool, int> ans;
    ans.second = left.second + right.second;

    if(ans.second == root->data && left.first && right.first)
    {
        ans.second += root->data;
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}