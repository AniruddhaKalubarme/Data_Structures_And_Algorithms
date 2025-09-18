#include<iostream>
using namespace std;

void HeapiFy(int arr[], int n, int index)
{
    int largest = index;
    int left = index*2;
    int right = index*2+1;

    if(left<=n && arr[largest]<arr[left])
        largest = left;

    if(right<=n && arr[largest]<arr[right])
        largest = right;

    if(largest != index)
    {
        swap(arr[largest], arr[index]);
        HeapiFy(arr, n, largest);
    }
}

int main()
{
    int arr[] = {-1,70,60,55,45,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<size<<endl;
    int index = size-1;
    while(index>0)
    {
        swap(arr[1], arr[index]);

        index--;

        HeapiFy(arr, index, 1);
    }

    for(int i = 1; i<size; i++)
        cout<<arr[i]<<" -> ";

    return 0;
}