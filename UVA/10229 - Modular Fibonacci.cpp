#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
        return 0;



    return fib(n-1)+fib(n-2);
}

int power(int m)
{
    if(m==1)
        return 2;

    return 2*power(m-1);
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {

        int F = fib(n);
        int P = power(m);
        if(F>P)
            F = F-P;

        cout<<F%P<<endl;

    }

    return 0;
}
