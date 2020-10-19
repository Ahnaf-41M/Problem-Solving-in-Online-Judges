#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
     ll n,t,i,j,g,MaxWt,mx=0,p,cost,wt;

     scanf("%lld",&t);

     while(t--)
     {
          scanf("%lld",&n);
          mx=0;
          ll dp[31] = {};
          for(i = 1; i <= n; i++ )
          {
               scanf("%lld%lld",&cost,&wt);

               for(j = 30; j >= wt; j--) //tabulation method
               {
                    if(dp[j]<dp[j-wt]+cost)
                         dp[j] = dp[j-wt]+cost;
               }
          }
          scanf("%lld",&g);

          for(i = 0; i < g; i++)
          {
               scanf("%lld",&MaxWt);
               mx+=dp[MaxWt];
          }
          printf("%lld\n",mx);


     }

}
