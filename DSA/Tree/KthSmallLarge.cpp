void FindKthSmaller(Node* root, int &k, int &element)
{
    if(root == NULL)
        return;
        
    FindKthSmaller(root->left, k, element);
    
    k--;
    if(k==0)
    {
        element = root->data;
    }
    
    FindKthSmaller(root->right, k, element);
}

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        int ans = -1;
        FindKthSmaller(root, k, ans);
        return ans;
    }
};