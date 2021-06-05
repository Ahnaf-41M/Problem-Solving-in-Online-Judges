#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[MX];
void Solve(int tc)
{
   fill(dp, dp + MX, 1e9);

   int n, x;
   cin >> n >> x;

   int coin[n];
   for (int &d : coin) cin >> d;

   //dp[sum] contains minimum number of coins needs to make sum
   dp[0] = 0;

   for (int sum = 1; sum <= x; sum++) {
      for (int val : coin) {
         if (val <= sum)
            dp[sum] = min(dp[sum - val] + 1, dp[sum]);
      }
   }
   cout << (dp[x] >= 1e9 ? -1 : dp[x]);
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