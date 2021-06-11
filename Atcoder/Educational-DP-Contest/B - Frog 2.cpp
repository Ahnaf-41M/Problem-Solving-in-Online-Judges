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

int n, h[MX], dp[MX], k;

int func(int pos)
{
   if (dp[pos] != -1) return dp[pos];

   int res = 1e9;
   for (int i = 1; i <= k; i++) {
      int j = i + pos;
      if (j > n) break;
      res = min(res, abs(h[j] - h[pos]) + func(j));
   }
   res = (res == 1e9 ? 0 : res);
   return dp[pos] = res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));
   cin >> n >> k;

   rep(i, 1, n) cin >> h[i];

   cout << func(1) << "\n";

   return 0;
}