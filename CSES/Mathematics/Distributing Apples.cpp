#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  MOD     1000000007
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int BigMod(int a, int p)
{
   int res = 1;
   while (p) {
      if (p & 1) res = res * a % MOD;
      a = a * a % MOD;
      p >>= 1;
   }
   return res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, m, up = 1, down = 1, k;
   cin >> n >> m;
   n += m - 1;
   for (int i = 0; i < m; i++) {
      up = up * (n - i) % MOD;
      down = down * (i + 1) % MOD;
   }

   int ans = up * BigMod(down, MOD - 2);
   ans %= MOD;
   cout << ans;

   return 0;
}