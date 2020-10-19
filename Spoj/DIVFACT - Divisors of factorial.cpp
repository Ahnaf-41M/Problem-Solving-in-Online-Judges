#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 1000006
#define mod 1000000007

ll a[mx];
//ll div[mx];
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
            for(j = 2; i*j <= mx; j++)
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
ll findDiv(ll n)
{
    ll i,res=1;
    for(i = 0; v[i]<=n; i++)
    {
        ll num=n;
        ll s=0;
        while(num)
        {
            s+=num/v[i];
            num/=v[i];
        }
        res=(res*(s+1))%mod;
    }
    return res;
}
int main()
{
    sieve();
    ll t,n;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",findDiv(n));
    }
}
