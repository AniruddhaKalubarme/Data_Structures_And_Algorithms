// find the Numbers which are divisible by 5 and 7
#include<iostream>
using namespace std;

int Divisible(int a, int b, int n)
{
    int d1 = n/a;
    int d2 = n/b;
    int d3 = n/(a*b);

    return d1+d2-d3;
}

int main()
{
    cout<<Divisible(5,7,40);
    return 0;
}