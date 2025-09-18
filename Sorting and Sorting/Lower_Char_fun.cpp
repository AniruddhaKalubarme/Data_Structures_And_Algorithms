#include<iostream>
using namespace std;

char ToLower(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        ch = ch - 'A' + 'a';
    return ch;
}

char ToUpper(char  ch)
{
    if(ch >= 'a' && ch <= 'z')
        ch = ch - 'a' + 'A';
    return ch;
}

string Reverse_Word_In_Sentance(string str)
{
    int i = 0, index = 0, start, end;
    do
    {
        // i++;
        if(str[i] == ' ' || str[i] == '\0')
        {
            start = index;
            end = i-1;
            while(start < end)
            {
                swap(str[start], str[end]);
                start++;
                end--;
            }

            index = i+1;
        }
    }while(str[i++] != '\0');
    return str;
}

int main()
{
    cout<<ToLower('Z')<<endl;
    cout<<ToUpper('m')<<endl;
    string str = Reverse_Word_In_Sentance("Aniruddha Kalubarme");
    cout<<str;
    return 0;
}
