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

char grid[1005][1005];
int H, W, dp[1005][1005];
int MOD = 1e9 + 7;

int func(int x, int y)
{
   if (x > H || y > W || grid[x][y] == '#') return 0;
   if (x == H && y == W) return 1;

   if (dp[x][y] != -1) return dp[x][y];

   int res = 0;
   res += ((func(x + 1, y) % MOD) + (func(x, y + 1) % MOD)) % MOD;

   return dp[x][y] = res % MOD;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));
   cin >> H >> W;
   rep(i, 1, H) rep(j, 1, W) cin >> grid[i][j];

   cout << func(1, 1);

   return 0;
}