#include<iostream>
using namespace std;

void Fibonacchi(int n)
{
    int a = 0, b = 1;
    cout<<a<<" "<< b<<" ";
    while(1)
    {
        int temp=a;
        a = b;
        b = temp+b;
        if(n<b)
            break;
        cout<<b<<" ";
    }
}

int isSorted(int *arr, int size)
{
    if(size == 0 || size == 1)
        return 1;
    
    if(arr[0]>arr[1])
        return 0;
    else
    {
        isSorted(arr+1, size-1);
        // return ans;
    }
}

int SumOfElements(int *arr, int size)
{
    if(size == 0)
        return 0;
    else
    {
        return arr[0] + SumOfElements(arr+1, size-1);
    }
    // return iSum;
}

int Linear_Search(int *arr, int size, int k)
{
    if(size == 0)
        return 0;

    if(arr[0] == k)
        return 1;
    else
        Linear_Search(arr+1, size-1, k);
}

int BinarySearch(int *arr, int s, int e, int k)
{
    if(s>e)
        return 0;
    
    int mid = (s+e)/2;
    if(arr[mid] == k)
        return mid;
    
    if(arr[mid]<k)
        BinarySearch(arr, mid+1, e, k);
    else
        BinarySearch(arr, s, mid-1, k);
}

void Reverse_string_1(string str, int n)
{
    if(n == -1)
        return;

    cout<<str[n];
    Reverse_string_1(str, n-1);
}

void Reverse_string_2(string &str, int s, int e)
{
    if(s>=e)
        return;

    swap(str[s++], str[e--]);
    Reverse_string_2(str, s, e);
}

int Power(int iNo, int pow)
{
    if(pow == 0)
        return 1;
    if(pow == 1)
        return iNo;
    
    if(pow%2 == 0)
        return Power(iNo,pow/2)*Power(iNo, pow/2);
    else
        return Power(iNo,pow/2)*Power(iNo, pow/2)*iNo;
}

void BubbleSort(int *arr, int n)
{
    if(n==1 || n==0)
        return;

    for(int i = 0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
    }

    BubbleSort(arr, n-1);
}

void SelectionSort(int *arr, int n, int j = 0)
{
    if(j == n)
        return;
    
    for(int i = 0; i<n; i++)
    {
        if(arr[j] < arr[i])
            swap(arr[j], arr[i]);
    }

    SelectionSort(arr, n, ++j);    
}

void InsertionSort(int *arr, int size, int index = 1)
{
    static int i = index;
    if(i == 0)
        return;
    if(index >= size)
        return;

    int key = arr[index];

    while(arr[index-1] > key && index > 0)
    {
        arr[index] = arr[index-1];
        index--;
    }
    arr[index] = key;
    InsertionSort(arr, size, ++i);
    
}

int main()
{
    // Fibonacchi(145);
    int Arr[] = {2,22, 7,24,26, 15,9,1,12};
    int size = sizeof(Arr)/4;
    
    /* int ans = isSorted(Arr, size);
    if(ans)
        cout<<"Array is sorted";
    else
        cout<<"Array is not sorted";
    */

    // cout<<"Sum is: "<<SumOfElements(Arr, size);

    // cout<<"Element Available: "<<Linear_Search(Arr, size, 9);

    // cout<<"Element is present: "<<BinarySearch(Arr, 0, size-1, 12);

    // Reverse_string_1("Aniruddha", 8);
    /* string name = "Aniruddha";
    Reverse_string_2(name, 0, 8);
    cout<<name;
    */
    
    // cout<<Power(2,11);

    // BubbleSort(Arr, size-1);
    // SelectionSort(Arr, size);
    
    InsertionSort(Arr, size);
    for(int i = 0; i<size; i++) cout<<Arr[i]<<" ";
    
    return 0;
}