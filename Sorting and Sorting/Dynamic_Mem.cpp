#include<iostream>
using namespace std;

int main()
{
    int rows = 3;
    int col = 3;

    int **Arr = new int* [rows];
    for(int i = 0; i<rows; i++)
    {
        Arr[i] = new int[col];
    }

    cout<<"Enter the elements: ";
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cin>>Arr[i][j];
        }
    }

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cout<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}