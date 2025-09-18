#include<iostream>
#include"BuildTree.cpp"
using namespace std;

void Sum(Node* root, int k, int &iCnt, vector<int> ans)
{
    if(root == NULL)
        return;

    ans.push_back(root->data);
    
    Sum(root->left, k, iCnt, ans);
    Sum(root->right, k, iCnt, ans); 

    int iSum = 0;

    for(int i = ans.size()-1; i>=0; i--)
    {
        iSum+=ans[i];
        if(iSum == k)
            iCnt++;
    }
    
} 