#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 5000000
ll a[mx];
vector<ll> v;

void sieve()
{
    ll i,j;
    a[2]=1;
    for(i = 3; i <= mx; i+=2)
        a[i]=1;

    for(i = 2; i <= sqrt(mx); i++)
    {
        if(a[i]==1)
        {
            for(j = 2; j*i <= mx; j++)
            {
                a[i*j]=0;
            }
        }
    }
    v.push_back(2);
    for(i = 3; i <= mx; i+=2)
    {
        if(a[i]==1)
            v.push_back(i);
    }
}
int main()
{
    sieve();
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",v[n-1]);
}
