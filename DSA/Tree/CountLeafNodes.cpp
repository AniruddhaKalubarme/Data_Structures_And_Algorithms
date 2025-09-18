#include"BuildTree.cpp"
#include<iostream>
using namespace std;

void Count(NODE *root, int &iCnt)
{
    if(root == NULL)
        return;

    Count(root->left, iCnt);
    if(root->left == NULL && root->right == NULL)
        iCnt++;
    Count(root->right, iCnt);
}

int main()
{
    NODE* root = NULL;
    root = BuildTree(root);
    // Display(root);
    int iCnt = 0;
    Count(root, iCnt);
    cout<<"Leaf NODES are : "<<iCnt<<endl;
    return 0;
}