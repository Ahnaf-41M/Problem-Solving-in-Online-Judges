#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           100005
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  gcd(a,b)     __gcd(a,b)
#define  lcm(a,b)     (a*b)/gcd(a,b)
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[101][MX], wt[101], val[101];
int n, W;
int inf = 1e18;

int call(int pos, int curV)
{
   if (curV == 0) return 0;
   if (pos > n || curV < 0) return 1e12;
   if (dp[pos][curV] != -1) return dp[pos][curV];

   int r1 = wt[pos] + call(pos + 1, curV - val[pos]);
   int r2 = call(pos + 1, curV);

   return dp[pos][curV] = min(r1, r2);
}
void Solve(int tc)
{
   // fill(dp[0], dp[100], inf);
   memset(dp, -1, sizeof(dp));

   int totV = 0;
   cin >> n >> W;

   rep(i, 1, n) {
      cin >> wt[i] >> val[i];
      totV += val[i];
   }

   irep(j, totV, 0) {
      int cur_wt = call(1, j); //if we can make our value j
      if (cur_wt <= W) {
         cout << j;
         return;
      }
   }
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