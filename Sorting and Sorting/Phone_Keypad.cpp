#include<iostream>
#include<vector>
using namespace std;
 
void Keypad(string Num, string Output, vector <string> &ans, string Mapping[10], int index = 0)
{
    if(index >= Num.length())
    {
        ans.push_back(Output);
        return;
    }

    int number = Num[index] - '0';
    string value = Mapping[number];

    for(int i = 0; i<value.length(); i++)
    {
        Output.push_back(value[i]);
        Keypad(Num, Output, ans, Mapping, index+1);
        Output.pop_back();
    }
}

int main(){
    string Num = "23";
    string Mapping[10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector <string> ans;
    string Output;
    Keypad(Num, Output, ans, Mapping);

    for(auto i : ans)
        cout<<i<<endl;
    return 0;
}