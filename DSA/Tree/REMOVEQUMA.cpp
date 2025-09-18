#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    for(int i = 0; i<str.length(); i++)
    {
        if(str[i] == ',' || str[i] == '[' || str[i] == ']')
            continue;
            
        cout<<str[i];
    }
    Sleep(10000);
}