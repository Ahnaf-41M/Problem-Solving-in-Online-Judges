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

int n, h[MX], dp[MX][3];

int func(int pos, int state)
{
   if (dp[pos][state] != -1) return dp[pos][state];

   int res = 0;
   if (pos + 1 <= n)
      res = abs(h[pos] - h[pos + 1]) + func(pos + 1, 1);
   if (pos + 2 <= n)
      res = min(res, abs(h[pos] - h[pos + 2]) + func(pos + 2, 2));

   return dp[pos][state] = res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));
   cin >> n;

   rep(i, 1, n) cin >> h[i];

   cout << func(1, 1);

   return 0;
}