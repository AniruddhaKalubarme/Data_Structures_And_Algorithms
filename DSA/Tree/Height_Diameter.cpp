#include"BuildTree.cpp"
#include<iostream>

using namespace std;

// Maximum Height
int Height(NODE *root)
{
    if(!root)
        return 0;

    int left = Height(root->left);
    int right = Height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

// Maximum length from one node to another node
int Diameter(NODE* root)
{
    if(root == NULL)
        return 0;

    int option1 = Diameter(root->left);
    int option2 = Diameter(root->right);
    int option3 = Height(root->left) + Height(root->right) + 1;

    int ans = max(option1, max(option2, option3));
    return ans;
}

//Approach - 2
pair<int, int> DiameterFast(NODE *root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
  
    pair<int,int> left = DiameterFast(root->left);
    pair<int,int> right = DiameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second)+1;

    return ans;
}

int main()
{
    NODE *root = NULL;
    root = BuildTree(root);
    // int height = Height(root);

    int height = Diameter(root);
    cout<<"\nHeight of tree is: "<<height<<endl;
    height = (DiameterFast(root)).first;
    cout<<"\nHeight of tree is: "<<height<<endl;
    return 0;
}