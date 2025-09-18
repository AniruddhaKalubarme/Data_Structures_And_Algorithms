#include<iostream>
#include<vector>
using namespace std;

void Permutation(string str, vector<string> &ans, int index = 0)
{
    if(index==str.length())
    {
        ans.push_back(str);
        return;
    }

    for(int i = index; i<str.length(); i++)
    {
        swap(str[i], str[index]);
        Permutation(str, ans, index+1);
        swap(str[i], str[index]);
    }
}

int main(){
    string str = "abc";
    vector<string> ans;
    Permutation(str, ans);
    for(auto i : ans)
        cout<<i<<endl;
    return 0;
}