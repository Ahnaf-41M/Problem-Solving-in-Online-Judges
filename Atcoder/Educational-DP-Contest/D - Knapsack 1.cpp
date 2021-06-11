#include "bits/stdc++.h"
#define  MX         100005
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  int        long long
#define  PII        pair<int,int>
#define  all(v)     v.begin(),v.end()
#define  rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int n, W, dp[101][MX], wt[MX], val[MX];

int func(int pos, int curWt)
{
   if (pos > n) return 0;
   if (dp[pos][curWt] != -1) return dp[pos][curWt];

   int r1 = 0, r2 = 0;
   if (curWt + wt[pos] <= W)
      r1 = val[pos] + func(pos + 1, curWt + wt[pos]);
   r2 = func(pos + 1, curWt);
   return dp[pos][curWt] = max(r1, r2);
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));

   cin >> n >> W;

   rep(i, 1, n) {
      cin >> wt[i] >> val[i];
   }
   cout << func(1, 0);
   return 0;
}