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
#define  mod     1000000007
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

ll cnt_2, cnt_5;

struct info
{
   ll two, five, zero;
} fact[MX];

inline void prime_fact(ll N)
{
   while ( N % 2 == 0 )
   {
      N /= 2;
      cnt_2++;
   }
   while ( N % 5 == 0 )
   {
      N /= 5;
      cnt_5++;
   }
}
inline void pre_process()
{
   for (ll i = 1; i <= 1000000; i++) {
      if (i % 2 == 0 || i % 5 == 0)
         prime_fact(i);
      fact[i].zero = min(cnt_5, cnt_2);
      fact[i].five = cnt_5;
      fact[i].two  = cnt_2;
   }
}
int main()
{
   pre_process();

   ll t, n, r, p, q;
   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {
      scanf("%lld%lld%lld%lld", &n, &r, &p, &q);
      cnt_2 = 0, cnt_5 = 0;
      prime_fact(p);
      
      ll x = fact[n].five - fact[n - r].five - fact[r].five;
      ll y = fact[n].two - fact[n - r].two - fact[r].two;
      ll ans = min(x + cnt_5 * q, y + cnt_2 * q);

      printf("Case %d: %lld\n", k, ans);
   }

}