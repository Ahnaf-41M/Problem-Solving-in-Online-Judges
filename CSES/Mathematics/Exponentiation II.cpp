#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

const int mod = 1e9 + 7;

int BigMod(int a, int b, int MOD)
{
   int res = 1;

   while (b) {
      if (b & 1)
         res = (res * a) % MOD;
      a = (a * a) % MOD;
      b >>= 1;
   }
   return res % MOD;
}
void Solve()
{
   //According to Fermat's little theorem, a^b ≡ a^(b%(mod-1))
   int a, b, c;
   cin >> a >> b >> c;

   cout << BigMod(a, BigMod(b, c, mod - 1), mod) << endl;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;

   while (T--)
      Solve();

   return 0;
}