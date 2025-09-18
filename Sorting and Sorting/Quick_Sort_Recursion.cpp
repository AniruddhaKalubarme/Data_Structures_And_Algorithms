#include<iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivote = arr[s], iCnt = 0;

    for(int i = s+1; i<=e; i++)
    {
        if(arr[i]<pivote)
            iCnt++;
    }
    
    int PivotIndex = s+iCnt;
    swap(arr[PivotIndex], arr[s]);
     
    int i = s,j = e;
    while(i<PivotIndex && j>PivotIndex)
    {
        while(arr[i] < pivote)
            i++;

        while(arr[j] > pivote)
            j--;

        if(i<PivotIndex && j>PivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return PivotIndex;
}

void Quick(int *arr, int s, int e)
{
    if(s>=e) return;

    int p = partition(arr, s, e);

    // for left sort    
    Quick(arr, s, p-1);
    
    // Right part sort
    Quick(arr, p+1,e);
}

int main()
{
    int arr[] = {12,6,69,63,56,89,52,14,21,56,85,201};
    int size = sizeof(arr)/4;

    Quick(arr, 0, size-1);

    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    return 0;
}