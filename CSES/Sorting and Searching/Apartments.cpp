#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, m, k, ans = 0;
   multiset<int> app, expct;

   cin >> n >> m >> k;

   for (int i = 1; i <= n; i++) {
      int d; cin >> d;
      expct.insert(d);
   }
   for (int i = 1; i <= m; i++) {
      int d; cin >> d;
      app.insert(d);
   }

   for (int x : expct) {
      auto it = app.lower_bound(x - k);
      if (it != app.end() && abs(*it - x) <= k) {
         app.erase(it);
         ans++; continue;
      }
      it = app.lower_bound(x + k);
      if (it != app.end() && abs(*it - x) <= k) {
         app.erase(it);
         ans++;
      }
   }
   cout << ans;
   return 0;
}