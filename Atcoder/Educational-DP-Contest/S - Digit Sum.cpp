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

string K;
int D;
int dp[MX][2][100];
const int MOD = 1e9 + 7;

int func(int pos, int isSmall, int curMod)
{
   if (pos == K.size()) return (curMod == 0);
   if (dp[pos][isSmall][curMod] != -1) return dp[pos][isSmall][curMod];

   int low = 0, high = K[pos] - '0', res = 0;

   if (isSmall) high = 9;
   if (!pos) res = -1; //for excluding the number 0.

   for (int i = low; i <= high; i++) {
      int newSmall = isSmall | (i < high);
      res = (res % MOD) + (func(pos + 1, newSmall, (curMod + i) % D) % MOD);
      res %= MOD;
   }
   return dp[pos][isSmall][curMod] = res % MOD;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   memset(dp, -1, sizeof(dp));

   cin >> K >> D;
   cout << func(0, 0, 0);
   return 0;
}