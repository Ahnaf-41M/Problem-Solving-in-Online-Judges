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

int n;
bool Can(int *p, int *m, int cur, int M)
{
   int cost = 0;
   rep(i, 0, n - 1) {
      int dif = cur - p[i];
      if (dif > 0) cost += dif * m[i];
      if (cost > M) return false;
   }
   return true;
}
int BSearch(int *p, int *m, int M)
{
   int l = 0, r = 2e18, res = 0;
   while (l <= r) {
      int mid = (l + r) >> 1;
      if (Can(p, m, mid, M)) { //if we can obtain mid as our answer
         res = max(mid, res);
         l = mid + 1;
      }
      else r = mid - 1;
   }
   return res;
}
void Solve(int tc)
{
   int M, ans;

   cin >> n >> M;

   int p[n], m[n];

   rep(i, 0, n - 1) cin >> p[i] >> m[i];
   ans = BSearch(p, m, M);

   cout << ans << "\n";

}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}