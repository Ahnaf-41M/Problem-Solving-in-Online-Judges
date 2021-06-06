#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[1005][MX];
int price[1005], pages[1005], n, x;

int KnapSack()
{
   /*dp[i][j] = maximum number of pages we can get for price at most j,
    only buying among the first i books*/

   for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= x; j++) {
         dp[i][j] = dp[i - 1][j];
         if (j >= price[i])
            dp[i][j] = max(dp[i - 1][j - price[i]] + pages[i], dp[i][j]);
      }
   }
   return dp[n][x];
}
void Solve(int tc)
{
   cin >> n >> x;
   rep(i, 1, n) cin >> price[i];
   rep(i, 1, n) cin >> pages[i];

   int ans = KnapSack();
   cout << ans;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T = 1;
   //cin >> T;
   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }


   return 0;
}