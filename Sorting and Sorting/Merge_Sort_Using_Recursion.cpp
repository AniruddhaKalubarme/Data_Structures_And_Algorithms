#include<iostream>
using namespace std;

void Merge(int *arr, int s, int e)
{
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int MainIndex = s;
    for(int i = 0; i<len1; i++)
    {
        first[i] = arr[MainIndex++];
    }

    for(int i = 0; i<len2; i++)
    {
        second[i] = arr[MainIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    MainIndex = s;

    while(index1<len1 && index2<len2)
    {
        if(first[index1]>=second[index2])
            arr[MainIndex++] = second[index2++];
        else
            arr[MainIndex++] = first[index1++];
    }

    while(index1<len1)
        arr[MainIndex++] = first[index1++];

    while(index2<len2)
        arr[MainIndex++] = second[index2++];

}

void Devide(int *arr, int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = (s+e)/2;

    Devide(arr, s, mid);
    Devide(arr, mid+1, e);

    Merge(arr, s, e);
}

int main()
{
    int arr[] = {12,6,69,63,56,89,52,14,21,56,85,201};
    int size = sizeof(arr)/4;

    Devide(arr, 0, size-1);

    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    return 0;
}