#include<iostream>
#include"BuildTree.cpp"
using namespace std;

void MaxSum(Node* root, pair<int , int> p, pair<int, int> &ans)
{
    if(root == NULL)
        return;

    p.first += root->data;
    if(root -> left == NULL && root -> right == NULL)
    {
        if(ans.second <= p.second)
        {
            if(ans.second == p.second)
                ans.first = max(ans.first, p.first);
            else
                ans.first = p.first;
            ans.second = p.second;
        }
    }

    
    MaxSum(root->left, make_pair(p.first, p.second+1), ans);
    MaxSum(root->right, make_pair(p.first, p.second+1), ans);
}

int main()
{
    NODE *root = NULL;
    root = BuildTree(root);

    pair<int, int> ans = {0,0};
    // ans = make_pair(0,0);
    MaxSum(root, make_pair(0,0), ans);
    cout<<"\n\nAns is: "<<ans.first<<endl;
    return 0;
}