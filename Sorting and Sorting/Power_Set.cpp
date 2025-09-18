#include<iostream>
#include<vector>
using namespace std;

void Power_Set(vector<vector<int>> &ans, vector <int> num, vector <int> output, int index = 0)
{
    if(index>=num.size())
    {
        ans.push_back(output);
        return;
    }
    
    //exclude
    Power_Set(ans, num, output, index+1);

    //include
    int element = num[index];
    output.push_back(element);
    Power_Set(ans, num, output, index+1);
    
}

int main(){
    vector<vector<int>> ans;
    vector<int> num = {1,2,3}, output;
    Power_Set(ans, num, output);

    for(auto it : ans)
    {
        for(auto j : it)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}

/*
Power set of string
#include<iostream>
#include<vector>
using namespace std;

void Power_Set(vector<string> &ans, string str, string output, int index = 0)
{
    if(index>=str.length())
    {
        ans.push_back(output);
        return;
    }
    
    //exclude
    Power_Set(ans, str, output, index+1);

    //include
    int element = str[index];
    output.push_back(element);
    Power_Set(ans, str, output, index+1);
    
}

int main(){
    vector<string> ans;
    string str = "abc", output;
    Power_Set(ans, str, output);

    for(auto it : ans)
    {
        for(auto j : it)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
*/