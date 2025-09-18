#include<iostream>
#include"BuildTree.cpp"
using namespace std;
int height(NODE *root)
{
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (max(left, right) + 1);
}

bool isBalanced(NODE* root)
{
    if(root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(diff && left && right)
        return true;
    else
        return false;
}

pair<bool, int> isBalFast(Node *root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true,0);
        return p;
    }
    pair<bool, int> left = isBalFast(root->left);
    pair<bool, int> right = isBalFast(root->right);

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    ans.first = (diff && left.first && right.first) ? true : false;
    

    return ans;
}


int main()
{

    return 0;
}