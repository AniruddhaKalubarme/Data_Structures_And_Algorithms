#include<iostream>
using namespace std;

bool IsBst(Node* root, int min, int max)
{
    if(root == NULL)
        return true;

    if(root->data >= min && root->data <= max)
    {
        bool left = IsBst(root->left, min, root->data);
        bool right = IsBst(root->right, root->data, max);

        return left && right;
    }
    else
        return false;
}
int main()
{
    bool chk = IsBst(root, INT_MIN, INT_MAX);
    cout<<chk<<endl;
    return 0;
}