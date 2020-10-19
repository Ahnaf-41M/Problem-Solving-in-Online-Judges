#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll solve(ll n)
{
     ll i,j;
     ll ret = 0;

     for(i = 2; i <= sqrt(n); i++)
     {
          j = n/i;
          ret+=(j+i)*(j-i+1)/2;
          ret+=(j-i)*i;
     }
     return ret;
}
int main()

{
    ll t,sum=0,i,x,j,k;

    scanf("%lld",&t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld",&x);

        printf("Case %lld: %lld\n",i,solve(x));
        sum=0;
    }
}
