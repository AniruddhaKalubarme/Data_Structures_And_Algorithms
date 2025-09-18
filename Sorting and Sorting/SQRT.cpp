#include<iostream>
using namespace std;

int SQRT(int iNo)
{
    int arr[iNo];
    for(int i = 1; i<=iNo/2; i++)
        arr[i-1] = i;
    int l = 0, h = iNo-1, mid, ans = 0;
    while(l<h)
    {
        mid = (l+h)/2;
        if(arr[mid]*arr[mid] <= iNo)
        {
            ans = arr[mid];
            l = mid+1;
        }
        else
            h = mid-1;
    }

    return ans;
}

double Precision(int digit, int ans, int n)
{
    double factor = 1;
    double answer;
    for(int i = 0; i<n; i++)
    {
        factor = factor / 10;
        for(double j = digit; j*j <= ans; j = j+factor)
        {
            answer = j;
        }
    }
    return answer;
}

int main()
{
    int iNo, prec;
    cout<<"Enter the Number AMOL: ";
    cin>>iNo;

    cout<<"Enter the Precision: ";
    cin>>prec;

    int digit = SQRT(iNo);

    cout<<"Ans : "<<Precision(digit, iNo, prec);
    return 0;
}