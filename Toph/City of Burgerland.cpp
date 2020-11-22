#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ll     long long int
#define  MX     100005
#define  pb     push_back
#define  all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

vector<ll> segTree[4 * MX], segSum[4 * MX];
ll n, m;
ll arr[MX];

void build(ll node, ll b, ll e)
{
   if (b == e) {
      segTree[node].pb(arr[b]);
      segSum[node].pb(arr[b]);
      return;
   }

   ll mid = (b + e) >> 1;
   ll left = node << 1;
   ll right = (node << 1) + 1;

   build(left, b, mid);
   build(right, mid + 1, e);
   merge(all(segTree[left]), all(segTree[right]), back_inserter(segTree[node]));

   ll cur = 0;
   for (auto it : segTree[node]) {
      segSum[node].pb(cur + it);
      cur += it;
   }
}
ll Query(ll node, ll b, ll e, ll l, ll r, ll x)
{
   if (b > r || e < l)
      return 0;
   if (b >= l && e <= r) {
      ll lb_x = lower_bound(all(segTree[node]), x) - segTree[node].begin();
      if (lb_x == 0) return 0;
      ll reqCap = lb_x * x - segSum[node][lb_x - 1];
      return reqCap;
   }

   ll mid = (b + e) >> 1;
   ll left = node << 1;
   ll right = (node << 1) + 1;

   ll r1 = Query(left, b, mid, l, r, x);
   ll r2 = Query(right, mid + 1, e, l, r, x);

   return r1 + r2;
}
int main()
{
   scanf("%lld%lld", &n, &m);

   for (ll i = 1; i <= n; i++)
      scanf("%lld", &arr[i]);

   build(1, 1, n);

   while ( m-- )
   {
      ll l, r, cap;
      scanf("%lld%lld%lld", &l, &r, &cap);
      printf("%lld\n", Query(1, 1, n, l, r, cap));
   }
}