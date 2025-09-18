#include<iostream>
using namespace std;

void Down_Up_Travel(int arr[][3], int iRow, int iColumn)
{
    for(int i = 0; i<iColumn; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0; j<iRow; j++)
            {
                cout<<arr[j][i]<<" ";
            }
        }
        else
        {
            for(int j = iRow-1; j>=0; j--)
            {
                cout<<arr[j][i]<<" ";
            }
        }
    }
}

void Spiral_Array(int arr[][3], int iRow, int iColumn)
{
    int Total = iRow * iColumn;
    int iCount = 0;

    // Initialisation
    int iStart_row = 0;
    int iStart_col = 0;
    int iEnd_row = iRow - 1;
    int iEnd_col = iColumn - 1;

    while(iCount<Total)
    {
        for(int i = iStart_col; i <= iEnd_col; i++)
        {
            cout<<arr[iStart_row][i]<<" ";
            iCount++;
        }
        iStart_row++;

        for(int i = iStart_row; i <= iEnd_row; i++)
        {
            cout<<arr[i][iEnd_col]<<" ";
            iCount++;
        }
        iEnd_col--;

        for(int i = iEnd_col; i>=iStart_col; i--)
        {
            cout<<arr[iEnd_row][i]<<" ";
            iCount++;
        }
        iEnd_row--;

        for(int i = iEnd_row; i >= iStart_row; i--)
        {
            cout<<arr[i][iStart_col]<<" ";
            iCount++;
        }
        iStart_col++;
    }
    
}

int main()
{
    int Arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // Down_Up_Travel(Arr,3,3);
    Spiral_Array(Arr, 3, 3);
    return 0;
}