/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void inorder(TreeNode *root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> Merge(vector<int> in1, vector<int> in2)
{
    vector<int> ans(in1.size()+in2.size());
    
    int s1 = 0, s2 = 0, i = 0;
    while(s1<in1.size() && s2<in2.size())
    {
        if(in1[s1] > in2[s2])
        {
            ans[i++] = in2[s2++];
        }
        else if(in1[s1] < in2[s2])
        {
            ans[i++] = in1[s1++];
        }
        else
        {
            ans[i++] = in1[s1++];
            ans[i++] = in2[s2++];
        }
    }
    
    while(s1<in1.size())
    {
        ans[i++] = in1[s1++];
    }
    
    while(s2<in2.size())
    {
        ans[i++] = in2[s2++];
    }
    
    return ans;
}

TreeNode* construct(vector<int> in, int s, int e)
{
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode* newn = new TreeNode(in[mid]);
    
    newn->left = construct(in, s, mid-1);
    newn->right = construct(in, mid+1, e);
    
    return newn;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);
    
    vector<int> ans = Merge(in1, in2);
    TreeNode* root = construct(ans, 0, ans.size()-1);
    ans.clear();
    inorder(root, ans);
    return ans;
}

// Approach - 2
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    void BSTintoDLL(Node* root, Node* &Head)
    {
        if(root == NULL)
            return;
    
        BSTintoDLL(root->right, Head);
        
        root->right = Head;
        if(Head!=NULL)
            Head->left = root;
    
        Head = root;
        BSTintoDLL(root->left, Head);
    }
    
    Node* MergeLL(Node* Head1, Node* Head2)
    {
        Node* Head = NULL;
        Node* Tail = NULL;
    
        while(Head1 != NULL && Head2 != NULL)
        {
            if(Head1->data > Head2->data)
            {
                if(Head == NULL)
                {
                    Head = Tail = Head2;
                }
                else
                {
                    Tail->right = Head2;
                    Head2->left = Tail;
                    Tail = Head2;
                }
                Head2 = Head2->right;
            }
            else
            {
                if(Head == NULL)
                {
                    Head = Tail = Head1;
                }
                else
                {
                    Tail->right = Head1;
                    Head1->left = Tail;
                    Tail = Head1;
                }
                Head1 = Head1->right;            
            }  
        }
    
        while(Head1!=NULL)
        {
            Tail->right = Head1;
            Head1->left = Tail;
            Tail = Head1;
            Head1 = Head1->right;
        }
    
        while(Head2!=NULL)
        {
            Tail->right = Head2;
            Head2->left = Head1;
            Tail = Head2;
            Head2 = Head2->right;
        }
    
        return Head;
    }
    
    int count(Node* Head1)
    {
        int iCnt = 0;
        while(Head1!=NULL)
        {
            iCnt++;
            Head1 = Head1->right;
        }
        return iCnt;
    }
    
    Node* SortedToBST(Node* &Head, int n)
    {
        if(n<=0 || Head == NULL)
            return NULL;
    
        Node* left = SortedToBST(Head, n/2);
    
        Node* root = Head;
        root->left = left;
    
        Head = Head -> right;
    
        root->right = SortedToBST(Head , n - n/2 - 1);
        return root;
    }
    
    void inorder(Node *root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        Node* Head1 = NULL;
        BSTintoDLL(root1, Head1);
        Head1->left = NULL;

        Node* Head2 = NULL;
        BSTintoDLL(root2, Head2);
        Head2->left = NULL;
        
        Node* Head = MergeLL(Head1, Head2);
        int iCnt = count(Head);
        Head = SortedToBST(Head, iCnt);
        
        vector<int> ans;
        inorder(Head, ans);
        return ans;
    }
};

//Approach - 3
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    void Insert(Node* root, stack<Node*> &s)
    {
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    vector<int> Solve(Node* root1, Node* root2)
    {
        stack<Node*> s1, s2;
        vector<int> ans;
        
        Insert(root1, s1);
        Insert(root2, s2);
        
        while(!s1.empty() && !s2.empty())
        {
            
            int iNo1 = s1.top()->data;
            int iNo2 = s2.top()->data;
            
            if(iNo1>iNo2)
            {
                ans.push_back(iNo2);
                Node* temp = s2.top();
                s2.pop();
                Insert(temp->right, s2);
            }
            else
            {
                ans.push_back(iNo1);
                Node* temp = s1.top();
                s1.pop();
                Insert(temp->right, s1);
            }
        }
        
        while(!s1.empty())
        {
            ans.push_back(s1.top()->data);
            Node* temp = s1.top();
            s1.pop();
            Insert(temp->right, s1);           
        }
        
        while(!s2.empty())
        {
            ans.push_back(s2.top()->data);
            Node* temp = s2.top();
            s2.pop();
            Insert(temp->right, s2);            
        }
        
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans = Solve(root1, root2);
        return ans;
    }
};