#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
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

int main()
{
   ll t, a, b, LCM, c;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

   scanf("%lld", &t);

   for (int k = 1; k <= t; k++)
   {
      scanf("%lld%lld%lld", &a, &b, &LCM);
      ll r1 = lcm(a, b);
      if (LCM % r1 == 0) {
         ll tmp = LCM / r1;
         for (ll j = tmp; j <= LCM; j += tmp) {
            if (lcm(r1, j) == LCM) {
               printf("Case %d: %lld\n", k, j);
               break;
            }
         }
      }
      else
         printf("Case %d: impossible\n", k);
   }
}