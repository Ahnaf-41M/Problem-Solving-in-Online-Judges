#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      1000005
#define  inf     1000000
#define  mod     1000003
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
#define  all(v)          v.begin(),v.end()
#define  ZERO(a)         memset(a,0,sizeof(a))
#define  MINUS(a)        memset(a,-1,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

ll fact[MX + 5], n, r;

inline void pre_process()
{
   fact[0] = 1;
   for (ll i = 1; i <= MX; i++)
      fact[i] = (fact[i - 1] * i) % mod;
}
//Below function calculates (a^n) % mod
ll modular_inverse(ll a, ll n, ll MOD)
{
   ll x = 1, y = a;

   while (n)
   {
      if (n & 1)
         x = (x % MOD * y % MOD) % MOD;
      y = (y * y) % MOD;
      n /= 2;
   }
   return x;
}
int main()
{
   pre_process();

   int t;
   scanf("%d", &t);

   for (int k = 1; k <= t; k++)
   {
      scanf("%lld%lld", &n, &r);
      ll r1 = modular_inverse(fact[r], mod - 2, mod);
      ll r2 = modular_inverse(fact[n - r], mod - 2, mod);
      ll ans = (fact[n] * r1 * r2) % mod;
      printf("Case %d: %lld\n", k, ans);
   }
}