#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.length() % 2 == 1)
  {
    return -1;
  }
  stack<char> st;
  for(char ch : str)
  {
    if(ch == '{' || st.empty())
    {
      st.push(ch);
    }
    else
    {
      if (st.top() == '{' && ch == '}')
      {
        st.pop();
      }
      else
      {
        st.push(ch);
      }
    }
  }

  int a = 0, b = 0;
  while(!st.empty()){
    if(st.top() == '{')
      a++;
    else
      b++;
    st.pop();
  }

  return ((a+1)/2) + ((b+1)/2);
}