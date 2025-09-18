string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    for(int i = 0; i<arr[0].size(); i++)
    {
        bool flag = true;
        for(int j = 0; j<arr.size(); j++)
        {
            if(arr[0][i] != arr[j][i])
            {
                flag = false;
                break;
            }
            
        }
        if(flag)
        {
            ans+=arr[0][i];
        }
        else
            break;
    
    }

    return ans;
}

// Approach - 2
class Node
{
    public:
    char data;
    Node* children[26];
    int ChildCount;
    bool isTerm;

    Node(char d)
    {
        data = d;
        for(int i = 0; i<26; i++)
        {
            children[i] = NULL;
        }
        ChildCount = 0;
        isTerm = false;
    }
};

void Insert(Node* root, string word)
{
    if(word.length() == 0)
    {
        root->isTerm = true;
        return;
    }

    int index = word[0]-'a';
    Node* child = new Node(word[0]);

    if(root -> children[index] != NULL)
    {
        child = root -> children[index];
    }
    else
    {
        root->children[index] = child;
        root->ChildCount++;
    }

    Insert(child, word.substr(1));
}

void FindThePrefix(Node* root, string word, string &ans)
{
    if(word.length() == 0|| root->ChildCount != 1 || root->isTerm)
    {
        return;
    }

    int index = word[0] - 'a';
    ans+=word[0];
    FindThePrefix(root->children[index], word.substr(1), ans);
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    Node* root = new Node('\0');

    for(int i = 0; i<arr.size(); i++)
    {
        Insert(root, arr[i]);
    }

    FindThePrefix(root, arr[0], ans);
    return ans;
}