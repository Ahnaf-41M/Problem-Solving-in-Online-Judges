#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           150000
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int ar[101], dp[101][MX];
int n;

int call(int pos, int curVal)
{
   if (curVal == 0) return 1;
   if (pos > n) return 0;
   if (dp[pos][curVal] != -1) return dp[pos][curVal];

   int r1 = call(pos + 1, curVal - ar[pos]);
   int r2 = call(pos + 1, curVal);

   return dp[pos][curVal] = r1 | r2;
}
void Solve(int tc)
{
   memset(dp, -1, sizeof(dp));
   int sum = 0;
   vector<int> ans;

   cin >> n;
   rep(i, 1, n) {
      cin >> ar[i];
      sum += ar[i];
   }

   rep(val, 1, sum) {
      if (call(1, val))
         ans.pb(val);
   }
   // cout << sum << "\n";
   cout << ans.size() << "\n";
   for (int x : ans) cout << x << " ";

   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}