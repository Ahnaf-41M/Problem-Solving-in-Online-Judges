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
//dp[k] = 1 means the current player will win if there are k elements remaining

int dp[MX];
int n, k, ar[101];

int func(int k)
{
   if (k == 0) return 0;
   if (dp[k] != -1) return dp[k];

   int res = 0;
   rep(i, 1, n) {
      if (ar[i] > k) continue;
      //if the current player can make 0 stone by taking numbe ar[i]
      if (func(k - ar[i]) == 0) {
         res = 1;
         break;
      }
   }
   return dp[k] = res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));

   cin >> n >> k;
   rep(i, 1, n) cin >> ar[i];

   if (func(k)) cout << "First";
   else cout << "Second";
   return 0;
}