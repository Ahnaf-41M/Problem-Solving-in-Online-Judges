#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           100005
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
#define  IOS          ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>, //less_equal for multiset
   rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;

void Solve(int tc)
{
   int n, ans = 0;
   map<string, int> mp;
   vector<string> v;
   ordered_set<int> S;

   cin >> n;

   rep(i, 1, n) {
      string s; cin >> s;
      v.pb(s);
   }
   rep(i, 1, n) {
      string s; cin >> s;
      mp[s] = i;
   }

   irep(i, n - 1, 0) {
      ans += S.order_of_key(mp[v[i]]);
      S.insert(mp[v[i]]);
   }

   cout << ans << "\n";
}
int main()
{
   IOS

   int T = 1;
   cin >> T;
   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

}