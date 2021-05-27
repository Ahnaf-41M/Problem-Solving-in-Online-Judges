#include "bits/stdc++.h"
#define  MX         55
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  int        long long
#define  PII        pair<int,int>
#define  all(v)     v.begin(),v.end()
#define  rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int dp[MX][MX], ar[MX], n, len;
int inf = 1e18;

int call(int L, int R)
{
   if (R - L == 1) return 0; //we cannot make cut at the edges of an wood
   if (dp[L][R] != inf) return dp[L][R];

   int res = inf;
   rep(i, L + 1, R - 1) {
      int cur = ar[R] - ar[L];
      int left = call(L, i); //result for left sub-problem
      int right = call(i, R); //result for right sub-problem
      res = min(res, cur + left + right);
   }
   return dp[L][R] = res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   while (cin >> len) {
      if (!len) break;

      cin >> n;
      rep(i, 1, n) cin >> ar[i];
      ar[n + 1] = len;

      fill(dp[0], dp[MX], inf);

      cout << "The minimum cutting is " << call(0, n + 1) << ".\n";
   }


   return 0;
}