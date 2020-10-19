#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    long long int f[81];
    f[0] = 1;
    f[1] = 1;

    for(i = 2; i <= 80; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    while(cin>>n,n>0)
    {
        cout<<f[n]<<endl;
    }
}
