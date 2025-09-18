#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(char ch:s)
    {
        if(ch >= 'a' && ch <= 'z')
            continue;
        else if(st.empty())
        {
            st.push(ch);
        }
        else
        {
            if(st.top() == '(' && ch == ')')
            {
                return true;
            }
            if(ch == ')')
            {
                while(st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    return false;
}
