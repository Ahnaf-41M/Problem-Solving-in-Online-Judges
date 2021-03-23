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

ll Fact(ll x)
{
   ll found = 0;
   for (ll i = 2; i * i <= x; i++)
   {
      ll tmp = x;
      found = 0;
      while ( tmp % i == 0 ) {
         tmp /= i;
         found++;
      }
      if ( tmp == 1 )
         break;
   }
   if (found)
      return found;
   return 1;

}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ll t, x;

   scanf("%lld", &t);

   for (int k = 1; k <= t; k++)
   {
      scanf("%lld", &x);
      ll p = Fact(abs(x));
      if (x < 0) {
         /*If x is a negetive number and x = a^p, then p must be
           odd.(i.e. x = -16,then p = 1,as,(-2)^4 =(-4)^2= 16.
           Only, (-16)^1 = -16. Thus p = 1.*/
         while ( p % 2 == 0 )
            p /= 2;
         printf("Case %d: %lld\n", k, p);
      }
      else
         printf("Case %d: %lld\n", k, p);
   }
}
