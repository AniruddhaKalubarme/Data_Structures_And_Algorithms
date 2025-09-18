#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Bruete-Force
void Celebrity(int n, int arr[][3])
{
    for(int i = 0; i<n; i++)
    {
        bool tag1 = true;
        bool tag2 = true;
        for(int j = 0; j<n; j++)
        {
            if(arr[i][j] == 1 && i!=j)
            {
                tag1 = false;
            }
        }

        if(tag1)
        {
            for(int j = 0; j<n; j++)
            {
                if(arr[j][i] == 0 && i!=j)
                {
                    tag2 = false;
                }
            }
        }

        if(tag1 && tag2)
        {
            cout<<"Celebrity: "<<i<<endl;
            break;
        }
    }
}

void CelebrityFind(vector<vector<int>> arr, int n)
{
    stack<int> s;
    for(int i = 0; i<n; i++)
        s.push(i);

    int element;
    while(s.size()>1)
    {
        int a, b;
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();

        if(arr[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }
    
    element = s.top();
    bool tag1 = true;
    int tag2 = true;
    for(int i = 0; i<n; i++)
    {
        if(arr[i][element] != 1 && i!=element)
            tag1 = false;

        if(arr[element][i] != 0 && i!=element)
            tag2 = false;
    }

    if(tag1 && tag2)
    {
        cout<<"CELEBRITY IS : "<<element<<endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};
    // Celebrity(3,arr);
    CelebrityFind(arr, arr.size());

    
    return 0;
}