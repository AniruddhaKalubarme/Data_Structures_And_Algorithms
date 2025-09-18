#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node
{
    public:
    char data;
    Node* children[26];
    bool isTerm;

    Node(char data):data(data), isTerm(false)
    {
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }

};

class TRIE
{
    public:
    Node *root;
    TRIE()
    {
        root = new Node('\0');
    }

    void InsertChar(Node* &root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerm = true;
            return;
        }

        int index = word[0]-'a';
        Node* child = new Node(word[0]);

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            root->children[index] = child;
        }

        InsertChar(child, word.substr(1));
    }

    void Insert(string word)
    {
        InsertChar(root, word);
    }
    
    bool SearchChar(Node* root, string word)
    {
        if(word.length() == 0)
        {
            return root->isTerm;
        }
        
        Node* child = NULL;
        int index = word[0]-'a';
        if(root->children[index] != NULL)
        {
            child = root->children[index];
            return SearchChar(child, word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool Search(string word)
    {
        Node* temp = root;
        return SearchChar(temp, word);
    }

    bool RemoveChar(Node* &root, string word, stack<Node*> &del)
    {
        if(word.length()==0)
        {
            if(root->isTerm == true)
            {
                del.push(root);
                root->isTerm = false;
                return true;
            }
            else
            {
                return false;
            }
        }

        int index = word[0] - 'a';

        if(root->children[index] != NULL)
        {
            del.push(root->children[index]);
            return RemoveChar(root->children[index], word.substr(1), del);
        }
        else
        {
            return false;
        }
    }

    void Remove(string word)
    {
        stack<Node*> del;
        bool chk = RemoveChar(root, word, del);

        // To Delete that Nodes
        // cout<<chk;
        if(chk)
        {
            int index = -1;
            while(!del.empty())
            {
                Node* top = del.top();
                del.pop();
                
                int iCnt = 0;
                
                for(int i = 0; i<26; i++)
                {
                    if(top->children[i] != NULL) iCnt++;
                }
                
                if(iCnt<=1)
                {
                    index = top->data - 'a';
                    delete top;
                }
                else
                {
                    top->children[index] = NULL;
                    return;
                }
            }
        }
        else
        {
            cout<<"That word is not present!!"<<endl;
        }
    }
};

int main()
{
    TRIE *T = new TRIE();
    T->Insert("aniruddha");
    cout<<"is String present: "<<T->Search("aniruddha")<<endl;
    
    T->Remove("aniruddha");
    cout<<"is String present: "<<T->Search("aniruddha")<<endl;
    return 0;
}