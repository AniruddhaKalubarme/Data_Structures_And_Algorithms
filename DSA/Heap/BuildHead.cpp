#include<iostream>
#include<stdio.h>
using namespace std;

class BuildHeap
{
    int arr[100];
    int MainIndex = 0;

    public:

    void Insert(int data)
    {
        MainIndex++;
        int index = MainIndex;
        arr[index] = data;
        while(index>1)
        {
            int parent = index/2;
            // Check parent nodes data
            if(arr[parent]<data)
            {
                swap(arr[index], arr[parent]);
                index = index/2;
            }
            else
            {
                break;
            }
        }

    }

    void Delete()
    {
        if(MainIndex == 0)
            return;

        // swap first and last element
        arr[1] = arr[MainIndex];

        //Last Element remove
        MainIndex--;
        
        int i = 1;
        while(true)
        {
            int largest = i;
            int LeftIndex = i*2;
            int RightIndex = i*2 + 1;

            if(LeftIndex<=MainIndex && arr[LeftIndex] > arr[largest])
            {
                largest = LeftIndex;
            }
            
            if(RightIndex<=MainIndex && arr[RightIndex] > arr[largest])
            {
                largest = RightIndex;
            }

            if(largest != i)
            {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else
                return;
        }
    }

    void HeapiFy(int arr[], int n, int index)
    {
        int largest = index;
        int left = index*2;
        int right = index*2 + 1;

        if(left<n && arr[left]>arr[largest])
        {
            largest = left;
        }

        if(right<n && arr[right]>arr[largest])
        {
            largest = right;
        }

        if(largest != index)
        {
            swap(arr[index], arr[largest]);
            HeapiFy(arr, n, largest);
        }
    }

    void print()
    {
        for(int i = 1; i<=MainIndex; i++)
            cout<<arr[i]<<" -> ";
    }
};

int main()
{
    BuildHeap obj;
    // obj.Insert(50);
    // obj.Insert(55);
    // obj.Insert(53);
    // obj.Insert(52);
    // obj.Insert(54);
    // // obj.Insert(40);
    // obj.print();
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // cout<<endl;
    // obj.print();

    int arr[6] = {-1,54,53,52,55,56};
    int n = 5;
    for(int i = n/2; i>0; i--)
        obj.HeapiFy(arr, n+1, i);

    for(int i = 1; i<=n; i++)
        cout<<arr[i]<<" ";
    return 0;
}