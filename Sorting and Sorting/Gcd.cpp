#include<iostream>
using namespace std;

int Gcd1(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;

    while(a!=b)
    {
        if(a>b)
            a-=b;
        else if(a<b)
            b-=a;
    }

    return a;
}

int Gcd2(int a, int b)
{
    int rem = max(a,b)%min(a,b);
    while(rem!=0)
    {
        a = b;
        b = rem;
        rem = a%b;
    }

    return b;
}

int main()
{
    cout<<Gcd1(24,42)<<endl;
    cout<<Gcd2(24,42);
    return 0;
}