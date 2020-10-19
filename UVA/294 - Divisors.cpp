#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll i,j,n,m,cnt=0,t,mx;

     scanf("%lld",&t);

     while(t--)
     {
          ll num;
          scanf("%lld %lld",&n,&m);

          mx = INT_MIN;
          for(i = n; i <= m; i++)
          {
               for(j = 1; j <= sqrt(i); j++)
               {
                    if(i%j==0)
                    {
                         if(i/j==j)
                              cnt++;
                         else
                              cnt+=2;
                    }
               }
               if(mx<cnt)
               {
                    mx = cnt;
                    num = i;
               }
               cnt=0;
          }
          printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",n,m,num,mx);
     }
}
