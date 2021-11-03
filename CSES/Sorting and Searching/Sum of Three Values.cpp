#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

vector<PII> v1;
vector<int> target;
void Solve(int tc)
{
   int n, x;
   cin >> n >> x;

   rep(i, 1, n) {
      int p; cin >> p;
      v1.pb({p, i});
      target.pb(x - p);
   }
   sort(all(v1));

   rep(i, 0, n - 1) {
      int l = 0, r = n - 1;
      while (l < r) {
         if (v1[l].ff + v1[r].ff == target[i]
               && v1[l].ss != i + 1 && v1[r].ss != i + 1) {
            cout << i + 1 << " " << v1[l].ss << " " << v1[r].ss << "\n";
            return;
         }
         if (v1[l].ff + v1[r].ff < target[i]) l++;
         else r--;
      }

   }
   cout << "IMPOSSIBLE";
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}