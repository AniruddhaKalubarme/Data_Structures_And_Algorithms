void Maping(vector<int> in, map<int, int> &link)
{
    for(int i = 0; i<in.size(); i++)
    {
        link[in[i]] = i;
    }
}

Node* BuildTree(vector<int> in, vector<int> post, int &index, int SPo, int EPo, map<int, int> link)
{
    if(index<0 || SPo > EPo)
        return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);
    int pos = link[element];
    
    root->right = BuildTree(in, post, index, pos+1, EPo, link);
    root->left = BuildTree(in, post, index, SPo, pos-1, link);
    
    return root;
}

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        map<int, int> link;
        Maping(inorder, link);
        int index = inorder.size()-1;
        int n = inorder.size();
        return BuildTree(inorder, postorder, index, 0, n-1, link);
    }
};