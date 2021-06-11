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

int n, a[MX], b[MX], c[MX];
int dp[MX][2][2][2], k;

int func(int pos, int s1, int s2, int s3)
{
   if (pos > n) return 0;
   if (dp[pos][s1][s2][s2] != -1)
      return dp[pos][s1][s2][s2];

   int res = 0;
   if (s1) {
      res = max(res, b[pos] + func(pos + 1, 0, 1, 0));
      res = max(res, c[pos] + func(pos + 1, 0, 0, 1));
   }
   if (s2) {
      res = max(res, a[pos] + func(pos + 1, 1, 0, 0));
      res = max(res, c[pos] + func(pos + 1, 0, 0, 1));
   }
   if (s3) {
      res = max(res, a[pos] + func(pos + 1, 1, 0, 0));
      res = max(res, b[pos] + func(pos + 1, 0, 1, 0));
   }

   return dp[pos][s1][s2][s2] = res;

}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));
   cin >> n;

   rep(i, 1, n) {
      cin >> a[i] >> b[i] >> c[i];
   }
   cout << func(1, 1, 1, 1) << "\n";

   return 0;
}