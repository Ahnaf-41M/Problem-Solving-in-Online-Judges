#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll totient(ll n)
{
    ll res=n,i;
    if(n==1) return 1;

    if(n%2==0)
    {
        res-=res/2;
        while(n%2==0)
        {
            n/=2;
        }
    }
    for(i = 3; i*i <= n; i+=2)
    {
        if(n%i==0)
        {
            res-=res/i;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1)
        res-=res/n;

    return res;
}

int main()
{
    ll n,ans,t;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",totient(n));
    }
}
