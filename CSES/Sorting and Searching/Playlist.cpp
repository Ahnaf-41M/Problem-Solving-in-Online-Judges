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

void Solve(int tc)
{
   int n, ans = 0, j = 1, i = 1;
   map<int, int> last;

   cin >> n;
   int ar[n + 1];

   rep(i, 1, n) cin >> ar[i];

   while (i <= n) {
      while (j <= last[ar[i]])
         last[ar[j]]--, j++;
      last[ar[i]] = i;
      // cout << i << " " << j << "\n";
      ans = max(ans, i - j + 1);
      i++;
   }
   cout << ans << "\n";
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