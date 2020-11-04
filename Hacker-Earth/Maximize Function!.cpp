#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     INT_MAX
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  all(v)          v.begin(),v.end()
#define  clr(a,x)        memset(a,x,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  irep(i,a,b)     for(i = a; i >= b; i--)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

ll n, a[MX], k, sum, mx;

ll SUM(ll m)
{
   ll res = 0, i;

   rep(i, 1, n + 1) res += max(a[i] - m * i, 0ll);

   return res;
}
pair<ll, ll> find_Y_S()
{
   ll low = 1, high = mx;
   pair<ll, ll> res(0, 0);

   while (low <= high)
   {
      ll mid = (low + high) / 2;
      ll r1 = SUM(mid);
      ll r2 = SUM(mid + 1);

      res.ff = mid; res.ss = r1;
      // cout << mid << " " << r1 << " " << r2 << endl;
      if (r1 >= k && r2 < k)
         return res;

      if (r1 < k)
         high = mid - 1;
      else
         low = mid + 1;
   }
   if (res.ss >= k)
      return res;
}
int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif

   IOS
   ll t, i; cin >> t;

   W(t)
   {
      cin >> n >> k;

      sum = 0, mx = 0;
      rep(i, 1, n + 1) cin >> a[i], mx = max(mx, a[i]);

      pair<ll, ll> ans = find_Y_S();
      cout << ans.ff << " " << ans.ss << endl;
   }
}