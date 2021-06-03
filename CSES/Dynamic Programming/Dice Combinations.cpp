#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           1000005
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  gcd(a,b)     __gcd(a,b)
#define  lcm(a,b)     (a*b)/gcd(a,b)
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[MX], n;
int mod = 1e9 + 7, ans;
void Solve(int tc)
{
   cin >> n;
   dp[0] = dp[1] = 1, dp[2] = 2;
   dp[3] = 4, dp[4] = 8, dp[5] = 16, dp[6] = 32;

   if (n <= 6) cout << dp[n];
   else {
      rep(i, 7, n) {
         rep(j, 1, 6) {
            dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
         }
      }
      cout << dp[n];
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