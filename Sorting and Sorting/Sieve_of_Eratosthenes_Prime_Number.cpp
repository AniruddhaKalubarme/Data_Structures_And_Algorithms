#include<iostream>
using namespace std;

void Prime_Number(int n)
{
    int arr[n] = {0};
    for (int i = 2; i<=n; i++)
    {
        if(i*i > n) break;
        for(int j = i*i; j<=n; j+=i)
        {
            arr[j] = 1;
        }
    }

    for(int i = 2; i<=n; i++)
    {
        if(arr[i] == 0)
            cout<<i<<" ";
    }
}

int main()
{
    Prime_Number(50);
    return 0;
}