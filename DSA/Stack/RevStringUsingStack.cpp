#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str = "aniruddha";
    string ans = "";
    stack<char> s;
    for(int i = 0; str[i] != '\0'; i++)
        s.push(str[i]);

    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    cout<<ans<<endl;
    return 0;
}