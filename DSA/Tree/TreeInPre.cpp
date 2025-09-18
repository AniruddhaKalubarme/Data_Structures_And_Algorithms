int FindPos(int element, vector<int> IN, int n)
{
    for(int i = 0; i<n; i++)
    {
        if(IN[i] == element)
            return i;
    }

    return -1;
}

Node* ConstructTree(vector<int> IN, vector<int> PRE, int &index, int SInorder, int EInorder, int n)
{
    if(index >= n || SInorder>EInorder)
        return NULL;

    int element = PRE[index++];
    Node* root = new Node(element);
    int pos = FindPos(element, IN, n);

    root->left = ConstructTree(IN, PRE, index, SInorder, pos-1, n);
    root->right = ConstructTree(IN, PRE, index, pos+1, EInorder, n);
    
    return root;
}

class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int start = 0;
        return ConstructTree(inorder, preorder, start, 0, n-1, n);
    }
};