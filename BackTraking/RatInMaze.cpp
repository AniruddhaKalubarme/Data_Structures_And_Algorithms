#include <bits/stdc++.h>

bool isSafe(int x, int y, int n, vector<vector<int>> arr,  vector<vector<int>> visited)
{
    if(x<n && x>=0 && y<n && y>=0 && arr[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Find(vector<vector<int>> arr, int i, int j, vector<vector<int>> &visited, string str, vector<string> &ans, int n)
{    
    if(i == n-1 && j == n-1)
    {
        ans.push_back(str);
        return;
    }

    visited[i][j] = 1;
    if(isSafe(i+1, j, n, arr, visited))
    {
        str.push_back('D');
        Find(arr, i+1, j, visited, str, ans, n);
        str.pop_back();
    }
    if(isSafe(i, j-1, n, arr, visited))
    {
        str.push_back('L');
        Find(arr, i, j-1, visited, str, ans, n);
        str.pop_back();
    }
    if(isSafe(i, j+1, n, arr, visited))
    {
        // when we use concatation then there is no need to pop back
        str+='R';
        Find(arr, i, j+1, visited, str, ans, n);
        // str.pop_back();
    }
    if(isSafe(i-1, j, n, arr, visited))
    {
        str+='U';
        Find(arr, i-1, j, visited, str, ans, n);
        // str.pop_back();
    }
    visited[i][j] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));;
    if(arr[0][0] == 0)
        return ans;
    Find(arr, 0, 0, visited, "", ans, n);
    
    return ans;
}