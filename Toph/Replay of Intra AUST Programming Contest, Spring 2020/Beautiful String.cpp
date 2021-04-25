#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

int MOD = 999961;

bool cmp(string x, string y)
{
   if (x.size() == y.size())
      return x < y;
   return x.size() < y.size();
}
void Solve()
{
   int A, B, C, ar[4];
   vector<string> adj[5];

   rep(i, 1, 3) cin >> ar[i];
   rep(i, 1, 3) {
      rep(j, 1, ar[i]) {
         string s; cin >> s;
         adj[i].pb(s);
      }
      sort(all(adj[i]), cmp);
   }
   int ans = 0;

   for (string cur : adj[2]) {
      int x = lower_bound(all(adj[1]), cur, cmp) - adj[1].begin();
      int y = lower_bound(all(adj[3]), cur, cmp) - adj[3].begin();
      // cout << x << " " << y << " " << cur << endl;
      ans = (ans + (x % MOD * y % MOD) % MOD) % MOD;
   }
   cout << ans % MOD;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   //int T;
   //cin >> T;

   //while (T--)
   Solve();

   return 0;
}