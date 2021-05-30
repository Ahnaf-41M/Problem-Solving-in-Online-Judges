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

int dp[101][50500], ar[101], sum;
int n;

int call(int pos, int cur)
{
   if (pos > n) return abs((sum - cur) - cur);
   if (dp[pos][cur] != -1) return dp[pos][cur];

   int r1 = call(pos + 1, cur + ar[pos]);
   int r2 = call(pos + 1, cur);

   return dp[pos][cur] = min(r1, r2);
}
void Solve(int tc)
{
   sum = 0;
   cin >> n;
   rep(i, 1, n) cin >> ar[i], sum += ar[i];

   cout << call(1, 0) << "\n";

   rep(i, 0, n) rep(j, 0, sum) dp[i][j] = -1;
   return;

}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   memset(dp, -1, sizeof(dp));
   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}