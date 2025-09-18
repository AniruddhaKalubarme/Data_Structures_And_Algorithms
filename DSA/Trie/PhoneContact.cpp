class Node
{
    public:
    char data;
    Node* children[26];
    bool isTerm;

    Node(char d)
    {
        data = d;
        for(int i = 0; i<26; i++)
        {
            children[i] = NULL;
        }
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
    }

    Insert(child, word.substr(1));
}

void printSugg(Node* curr, vector<string> &temp, string prefix)
{
    if(curr->isTerm)
    {
        temp.push_back(prefix);
    }

    for(char ch = 'a'; ch<='z'; ch++)
    {
        Node* next = curr->children[ch-'a'];

        if(next != NULL)
        {
            prefix.push_back(ch);
            printSugg(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestion(Node* root, string str)
{
    string prefix = "";
    vector<vector<string>> output;
    Node* prev = root;
    
    for(int i = 0; i<str.length(); i++)
    {
        char lastch = str[i];

        prefix.push_back(lastch);

        Node* curr = prev->children[lastch - 'a'];

        if(curr == NULL)
            break;
        
        vector<string> temp;
        printSugg(curr, temp, prefix);

        output.push_back(temp);
        temp.clear();
        prev = curr;
    }

    return output;
}

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Node* root = new Node('\0');

    for(int i = 0; i<contactList.size(); i++)
    {
        Insert(root, contactList[i]);
    }

    return getSuggestion(root, queryStr);
}