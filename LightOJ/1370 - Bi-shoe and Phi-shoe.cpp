#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      1005251
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
template <typename T >  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

ll phi[MX + 5];
ll score[MX + 5];

inline void find_phi()
{
   int i, j;
   for (i = 1; i <= MX; i++)
      phi[i] = i;
   for (i = 2; i <= MX; i++)
      if (phi[i] == i)
         for (j = i; j <= MX; j += i)
            phi[j] -= phi[j] / i; //Inclusion_Exclusion Law used
   for (i = 2; i <= MX; i++)
      if (phi[i] <= MX && !score[phi[i]])
         score[phi[i]] = i;

   for (int i = MX-1; i >= 1; i--) {
      if (!score[i])
         score[i] = score[i + 1];
      else if (score[i + 1])
         score[i] = min(score[i], score[i + 1]);
   }

}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ll t, ks;
   find_phi();

   scanf("%lld", &t);

   rep(ks, 1, t + 1)
   {
      ll n, i;
      scanf("%lld", &n);
      ll a[n], ans = 0;

      rep(i, 0, n) {
         scanf("%lld", &a[i]);
         ans += score[a[i]];
      }
      printf("Case %lld: %lld Xukha\n", ks, ans);
   }


}