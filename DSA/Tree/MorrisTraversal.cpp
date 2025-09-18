vector<int> Inorder(Node* root)
{
    Node* curr = root;
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node* prev = curr->left;
            while(prev->right != NULL && prev->right != curr)
            {
                prev=prev->right;
            }
            
            if(prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    
    return ans;
}

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        return Inorder(root);
    }
}; 