#include<iostream>
using namespace std;

void Rotate_Array(int *arr, int *arr2, int iLength, int iRotate)
{
    int iPos;
    for(int i = 0; i<iLength; i++)
    {
        iPos = i+iRotate;
        if(iPos>=iLength)
            iPos %= iLength;

        arr2[iPos] = arr[i];
    }
    
}

int Check_Array_Rotated(int *arr, int iLength)
{
    int iCount = 0, i = 0;

    while(i<iLength)
    {
        if(arr[i]>arr[i+1])
        {
            iCount++;
            if(iCount > 1)
                return iCount;
        }
        i++;
    }
    return iCount;
}

int main()
{
    int array[] = {10,11,12,1,2,3,4,5,6,7,8};
    int iLength = sizeof(array)/4;
    int arr2[iLength];

    /* Rotate_Array(array, arr2, iLength, 2);
    for(int i = 0; i<iLength; i++)
    {
        cout<<arr2[i]<<" ";
    }
    */

    /* int chk = Check_Array_Rotated(array, iLength);
    if(chk == 0)
        cout<<"ALL SORTED";
    else if(chk == 1)
        cout<<"SINGLE SORTED";
    else
        cout<<"NOT SORTED";
    */
    return 0;
}