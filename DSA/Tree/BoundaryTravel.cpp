#include<iostream>
#include<vector>
#include"BuildTree.cpp"
using namespace std;

void leftTravel(NODE *root, vector<int> &ans)
{
    if(root == NULL || (root -> left == NULL && root -> right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if(root -> left)
        leftTravel(root->left, ans);
    else
        leftTravel(root->right, ans);
}

void LeafNODEs(NODE *root, vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }

    if((root -> left == NULL && root -> right == NULL))
    {
        ans.push_back(root->data);
        return;
    }

    LeafNODEs(root->left, ans);
    LeafNODEs(root->right, ans);
}

void rightTravel(NODE * root, vector<int> &ans)
{
    if(root == NULL || (root -> left == NULL && root -> right == NULL))
    {
        return;
    }

    if(root->right)
        rightTravel(root->right, ans);
    else
        rightTravel(root->left, ans);
    ans.push_back(root->data);
}

int main()
{
    NODE* root = BuildTree(root);
    vector<int> ans;
    if(root == NULL)
        return 0;
    
    // Only one NODE present
    if(root -> left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        goto Display;
    }

    ans.push_back(root->data);
    leftTravel(root->left, ans);
    LeafNODEs(root, ans);
    rightTravel(root->right, ans);

    Display:
    for(auto i : ans)
    {
        cout<<i<<" -> ";
    }

    return 0;
}