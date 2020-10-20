#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000000
ll a[mx];

void sieve()
{
    ll i,j;
    a[2]=1;
    for(i = 3;i <= mx; i+=2)
        a[i]=1;
    for(i = 2; i <= sqrt(mx);i++)
    {
        if(a[i]==1)
        {
            for(j = 2; i*j <= mx; j++)
            {
                a[i*j]=0;
            }
        }
    }
}
int main()
{
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,n,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        n = sqrt(x);
        if(n*n==x)
        {
            if(a[n]==1)
                cout<<"YES.\n";
            else
                cout<<"NO.\n";
        }
        else
            cout<<"NO.\n";
    }
}
