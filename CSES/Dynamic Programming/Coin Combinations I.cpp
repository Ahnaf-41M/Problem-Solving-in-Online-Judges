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

int dp[MX], n, ar[101], val;
int mod = 1e9 + 7;

int call(int pos, int curVal)
{
   if (curVal == 0) return 1;
   if (pos > n || curVal < 0) return 0;
   if (dp[curVal] != -1) return dp[curVal];

   int r1 = 0;
   for (int i = 1; i <= n; i++) {
      if (curVal >= ar[i]) {
         r1 += call(i, curVal - ar[i]);
      }
   }

   return dp[curVal] = r1 % mod;
}
void Solve(int tc)
{
   memset(dp, -1, sizeof(dp));
   cin >> n >> val;
   rep(i, 1, n) cin >> ar[i];
   cout << call(1, val);
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