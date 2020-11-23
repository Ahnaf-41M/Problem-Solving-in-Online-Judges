#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  pb   push_back
#define  ll   long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(ll i = a; i <= b; i++)

using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, arr[2 * MX], ans[2 * MX];
struct Query
{
   ll l, r, k, indx;
};
Query Q[2 * MX];
ll freq[2 * MX], cur_mx, F_freq[2 * MX], cur_num;
const ll block = 700;

bool cmp(Query a, Query b)
{
   if (a.l / block != b.l / block)
      return a.l < b.l;
   return a.r < b.r;
}

void Add(ll pos)
{
   ll val = arr[pos];
   if (F_freq[freq[val]])
      F_freq[freq[val]]--;
   freq[val]++;
   F_freq[freq[val]]++;
   cur_mx = max(freq[val], cur_mx);
}
void Remove(ll pos)
{
   ll val = arr[pos];
   if (F_freq[freq[val]])
      F_freq[freq[val]]--;

   if (freq[val])
      freq[val]--;
   F_freq[freq[val]]++;
   if (F_freq[cur_mx]==0)
      cur_mx--;
}
void AnswerQuery()
{
   ll cur_L = 1, cur_R = 0;

   rep(i, 1, m) {
      ll left = Q[i].l;
      ll right = Q[i].r;


      while (cur_L > left) cur_L--, Add(cur_L);
      while (cur_R < right) cur_R++, Add(cur_R);

      while (cur_L < left) Remove(cur_L), cur_L++;
      while (cur_R > right) Remove(cur_R), cur_R--;

      ans[Q[i].indx] = cur_mx;
   }
   rep(i, 1, m) cout << ans[i] << "\n";

}
int main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   cin >> n >> m;
   rep(i, 1, n) cin >> arr[i];

   rep(i, 1, m) {
      cin >> Q[i].l >> Q[i].r;
      Q[i].l++, Q[i].r++;
      Q[i].indx = i;
   }
   sort(Q + 1, Q + m + 1, cmp);
   AnswerQuery();
   return 0;
}