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

int dp[MX][11];
int n;

int call(int n, int digit)
{
   if (n == 0) return 0;
   if (dp[n][digit] != -1) return dp[n][digit];

   int tmp = n, res = 1e9;
   while (tmp) {
      int d = tmp % 10;
      if (d)
         res = min(res, 1 + call(n - d, d));
      tmp /= 10;
   }
   return dp[n][digit] = res;
}
void Solve(int tc)
{
   memset(dp, -1, sizeof(dp));
   cin >> n;
   cout << call(n, 0);
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