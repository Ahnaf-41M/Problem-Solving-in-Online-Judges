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

int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif

   IOS
   int t, n, i, j;
   cin >> t;

   rep(i, 1, t + 1)
   {
      cin >> n;
      map<int, string> mp;
      W(n)
      {
         string name;
         int len, wid, ht, area;
         cin >> name >> len >> wid >> ht;
         area = len * wid * ht;
         mp[area] = name;
      }
      auto it = mp.rbegin();
      auto it2 = mp.begin();
      if (mp.size() > 1)
         cout << "Case " << i << ": " << it->ss << " took chocolate from " << it2->ss << endl;
      else
         cout << "Case " << i << ": no thief\n";

   }
}