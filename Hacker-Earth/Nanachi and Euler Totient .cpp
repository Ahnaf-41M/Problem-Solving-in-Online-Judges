#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = pow(10,9)+7;

ll totient(ll n)
{
    ll i,ans=n;

    if(n%2==0)
    {
        ans-=ans/2;
        while(n%2==0)
        {
            n/=2;
        }
    }
    for(i = 3; i*i <= n; i++)
    {
        if(n%i==0)
        {
            ans-=ans/i;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1)
        ans-=ans/n;

    return ans%mod;
}

int main()
{
    ll n,res=1;
    scanf("%lld",&n);
    ll i;

    for(i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                res = res%mod*totient(i)%mod;
            }
            else
            {
                res = res%mod*totient(i)%mod;
                res = res%mod*totient(n/i)%mod;
            }
        }
    }
    printf("%lld\n",res);

}
