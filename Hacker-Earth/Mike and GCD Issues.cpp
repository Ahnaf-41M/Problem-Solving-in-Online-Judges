#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      200005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
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

vector<int> fact[MX], divisors[MX], prime;
int n, a[MX + 5], ans, Div[MX + 5];

void sieve()
{
   for (int i = 2; i * i < MX; i++)
      if (!Div[i])
         for (int j = i * i; j < MX; j += i)
            Div[j] = i;

   for (int i = 1; i <= MX; i++)
      if (!Div[i])
         Div[i] = i;
}
int main()
{
   // IOS
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

   sieve();

   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      int m = a[i];

      int j = 0;
      while ( m > 1 ) {
         int d = Div[m];
         divisors[i].pb(d);
         fact[d].pb(i);

         while ( m % d == 0 )
            m /= d;
      }
   }
   for ( int i = 1; i <= n; i++ ) {
      ans = -1;
      auto consider = [&](int j) {
         if (ans == -1 || make_pair(abs(j - i), j) < make_pair(abs(ans - i), i))
            ans = j;
      };

      for ( int prm : divisors[i] ) {
         const vector<int> &tmp = fact[prm];
         int idx = lower_bound(all(tmp), i) - tmp.begin();

         if ( idx != 0 )
            consider(tmp[idx - 1]);

         if ( idx != tmp.size() - 1 )
            consider(tmp[idx + 1]);
      }
      printf("%d ", ans);
   }
}