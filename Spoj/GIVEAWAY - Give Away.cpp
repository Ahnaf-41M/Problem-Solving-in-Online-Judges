#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  pb   push_back
#define  ll   long long
#define  endl "\n"
#define  MX   500005

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  all(v)          v.begin(), v.end()
#define  rep(i,a,b)      for(ll i = a; i <= b; i++)

using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

int n, q, blk_len;
int arr[MX];
vector<int> block[800];

inline void pre_process()
{
   int j = 1;
   blk_len = ceil(sqrt(n));

   rep(i, 1, n) {
      if (i != 1 && i % blk_len == 1) {
         sort(all(block[j]));
         block[++j].pb(arr[i]);
      }
      else
         block[j].pb(arr[i]);
   }
}
int Query(int a, int b, int c)
{
   int res = 0;
   int LB = (a + blk_len - 1) / blk_len;
   int RB = (b + blk_len - 1) / blk_len;

   if (LB == RB) {
      rep(i, a, b) if (arr[i] >= c) res++;
   }
   else
   {
      rep(i, a, LB * blk_len) if (arr[i] >= c) res++;
      rep(i, LB + 1, RB - 1) {
         int lbc = lower_bound(all(block[i]), c) - block[i].begin();
         res += (block[i].size() - lbc);
      }
      rep(i, ((RB - 1)*blk_len) + 1, b) if (arr[i] >= c) res++;
   }
   return res;
}
int main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   cin >> n;
   rep(i, 1, n) cin >> arr[i];
   pre_process();

   cin >> q;

   W(q)
   {
      int type, a, b, c;
      cin >> type;

      if (type == 0) {
         cin >> a >> b >> c;
         cout << Query(a, b, c) << endl;
      }
      else {
         cin >> a >> b;
         int blk = (a + blk_len - 1) / blk_len;
         int val = arr[a];
         int indx = lower_bound(all(block[blk]), val) - block[blk].begin();
         block[blk][indx] = b;
         sort(all(block[blk]));
         arr[a] = b;
      }
   }
   return 0;
}