#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
     ll n,m,i,j,k,l,cnt,g,h;

     while(scanf("%lld%lld",&n,&m)!=EOF)
     {
          cnt=0;
          ll mx=0;
          for(i = min(n,m); i <= max(n,m); i++)
          {
               g = i;
               while(g!=1)
               {
                    if(g&1)
                         g = g*3+1;
                    else
                         g/=2;
                    cnt++;
               }
               mx = max(mx,cnt);
               cnt=0;
          }
          printf("%lld %lld %lld\n",n,m,mx+1);
     }
}
