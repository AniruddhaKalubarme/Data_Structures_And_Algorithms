void Inorder(Node* root, vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }

    Inorder(root->left, ans);
    ans.push_back(root->data);  
    Inorder(root->right, ans);
}

bool FindSum(vector<int> ans, int iSum)
{
    int i = 0, j = ans.size()-1;
    while(i<j)
    {
        if(ans[i] + ans[j] == iSum)
            return true;

        if(ans[i] + ans[j] < iSum)
            i++;
        else
            j--;
    }

    return false;
}


class Solution {
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int findTarget(struct Node *root, int target) {
        vector<int> ans;
        Inorder(root, ans);
        return FindSum(ans, target);
    }
};