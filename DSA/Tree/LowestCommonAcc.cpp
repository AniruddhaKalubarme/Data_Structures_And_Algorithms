#include<iostream>
#include"BuildTree.cpp"
using namespace std;

NODE* LCA(NODE* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root -> data == n1 || root -> data == n2)
        return root;

    NODE* right = LCA(root->right, n1, n2);
    NODE* left = LCA(root->left, n1, n2);

    if(right != NULL && left != NULL)
        return root;
    else if(!right && !left)
        return NULL;
    else if(right == NULL && left != NULL)
        return left;
    else if(right != NULL && left == NULL)
        return right;
}

int main()
{
    NODE *root = NULL;
    root = BuildTree(root);

    return 0;
}