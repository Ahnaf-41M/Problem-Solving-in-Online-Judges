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
#define  rep(i,a,b)      for(ll i = a; i <= b; i++)
#define  irep(i,b,a)     for(ll i = b; i >= a; i--)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

int arr[MX], freq[MX], n, q, ans[50005], unq;
struct Query
{
   int l, r, indx;
} Q[50005];
const int block = 700;

bool cmp(Query a, Query b)
{
   if (a.l / block != b.l / block)
      return a.l < b.l;
   return a.r < b.r;
}
void Add(int pos)
{
   int val = arr[pos];
   if (!freq[val])
      unq++;
   freq[val]++;
}
void Remove(int pos)
{
   int val = arr[pos];
   if (freq[val] == 1)
      unq--;
   freq[val]--;
}
void AnswerQueries()
{
   int cur_L = 1, cur_R = 0;

   rep(i, 1, q)
   {
      int left = Q[i].l;
      int right = Q[i].r;

      while (cur_L > left) cur_L--, Add(cur_L);
      while (cur_R < right) cur_R++, Add(cur_R);

      while (cur_L < left) Remove(cur_L), cur_L++;
      while (cur_R > right) Remove(cur_R), cur_R--;

      ans[Q[i].indx] = unq;
   }
   rep(i, 1, q) printf("%d\n", ans[i]);
}
int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif

   int t; scanf("%d", &t);

   rep(i, 1, t)
   {
      unq = 0;
      scanf("%d%d", &n, &q);
      rep(i, 1, n) cin >> arr[i];

      rep(j, 1, q)
      {
         cin >> Q[j].l >> Q[j].r;
         Q[j].indx = j;
      }
      sort(Q + 1, Q + 1 + q, cmp);
      printf("Case %d:\n", i);
      AnswerQueries();
      clr(ans, 0);
      clr(Q, 0);
      clr(freq, 0);
   }

}