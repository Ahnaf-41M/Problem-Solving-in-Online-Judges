#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000000
ll a[mx];
ll v1[mx+5];
vector<ll> v;


void sieve()
{
     int i,j;
     a[2]=1;
     for(i = 3; i <= mx; i+=2)
          a[i]=1;
     for(i = 3; i <= sqrt(mx); i++)
     {
          if(a[i]==1)
          {
               for(j = 2; i*j <= mx; j++)
               {
                    a[i*j]=0;
               }
          }
     }

     v.push_back(0);
     v.push_back(2);
     for(i = 2; i <= mx; i++)
     {
          if(a[i]==1)
          {
               v.push_back(i);
          }
          else
          {
               v.push_back(v[i-1]);
          }
     }
     //ll x = INT_MAX;
     v[mx+1] = INT_MAX;
     for(i = mx; i>=2; i--)
     {
          if(a[i]==1)
          {
               v1[i]=i;
          }
          else
          {
               v1[i] = v1[i+1];
          }
     }
}
int main()
{
     sieve();
     ll n,t;

     scanf("%lld",&t);

     while(t--)
     {
          scanf("%lld",&n);
          if(abs(n-v1[n])>=abs(n-v[n]))
          {
               printf("%lld\n",v[n]);
          }
          else
              printf("%lld\n",v1[n]);

     }
}
