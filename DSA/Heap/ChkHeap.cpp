int Count(struct Node* root)
{
    if(root == NULL)
        return 0;
    
    int ans = 1 + Count(root->left) + Count(root->right);
    return ans;
}

bool isCBT(struct Node* root, int index, int iCnt)
{
    if(root == NULL)
        return true;
    
    if(index >= iCnt)
        return false;
    else
    {
        bool left = isCBT(root->left, index*2+1, iCnt);
        bool right = isCBT(root->right, index*2+2, iCnt);
        return (left && right);
    }
}

bool MaxHeap(struct Node* root)
{
    if(root->left == NULL && root->right == NULL)
        return true;
    
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        if(root->data < root->left->data && root->data < root->right->data)
        {
            return false;
        }
        else
        {
            bool left = MaxHeap(root->left);
            bool right = MaxHeap(root->right);
            return (left && right);
        }
    }
}

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        int iCnt = 0, index = 0;
        iCnt = Count(tree);
        return (isCBT(tree, index, iCnt) && MaxHeap(tree));
    }
};   