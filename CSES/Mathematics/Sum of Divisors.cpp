#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          unsigned long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int n, mod = 1e9 + 7, ans;

int BinExp(int a, int p, int MOD)
{
   int res = 1;
   while (p) {
      if (p & 1) res = (res * a) % MOD;
      a = (a * a) % MOD;
      p >>= 1;
   }
   return res;
}
int SOD()
{
   int invOf_2 = BinExp(2, mod - 2, mod);
   for (int i = 1; i * i <= n; i++) {
      int j = n / i;
      int x1 = (j + i) % mod;
      int x2 = (j - i + 1) % mod;
      int x3 = (((j - i) % mod) * (i % mod)) % mod;

      x2 = (((x1 * x2) % mod) * (invOf_2)) % mod;
      ans += x3 + x2;
      ans %= mod;
   }
   return ans;
}
void Solve(int tc)
{
   cin >> n;
   cout << SOD() << "\n";
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