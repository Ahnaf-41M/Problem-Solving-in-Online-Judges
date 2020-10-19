#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dp[2000002];
ll KS(ll value[],ll wt[],ll w,ll n)
{
     if(n==0||w==0)
          return 0;

     if(dp[n][w]!=-1)
          return dp[n][w];

     if(wt[n-1]<=w)
          return dp[n][w] = max(value[n-1]+KS(value,wt,w-wt[n-1],n-1),KS(value,wt,w,n-1));
     else
     {
          return dp[n][w] = KS(value,wt,w,n-1);
     }
}
int main()
{
     ll n,w,i;

     cin>>w>>n;
     ll value[n],wt[n];


     memset(dp,-1,sizeof(dp));

     for(i = 0; i < n; i++)
     {
          cin>>value[i]>>wt[i];
     }
     cout<<KS(value,wt,w,n)<<'\n';
}

