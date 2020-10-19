/* Every number can be represented as a power of 10.
   Let's say, n = 10^z (z is not necesserily be integer)
           => n = 10^x * 10^y (here x is integer and y is double)

   Suppose, x = n^k
   => log(x) = log(n^k)
   => log(x) = k*log(n)
   => x = 10^(k*log(n)) //as log is based 10.
*/
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      1000
#define  inf     1000000
#define  mod     1000
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

ll BigMod(ll n, ll k)
{
   ll res = 1;

   while ( k )
   {
      if (k & 1)
         res = (res % mod * n % mod) % mod;
      n = (n % mod * n % mod) % mod;
      k >>= 1;
   }
   return res;
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ll t, cs;
   scanf("%lld", &t);

   rep(cs, 1, t + 1)
   {
      ll n, k;
      double x;

      scanf("%lld%lld", &n, &k);
      x = k * (log10(n * 1.0));
      x -= floor(x);
      x = pow(10.0, x);
      x *= 100;

      ll leading = x;
      ll trailing = BigMod(n, k);

      printf("Case %lld: %03lld %03lld\n", cs, leading, trailing);
   }
}