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
   int n, x;
   map<int, PII> mp;

   cin >> n >> x;
   int ar[n + 1];
   rep(i, 1, n) cin >> ar[i];

   rep(i, 1, n) rep(j, i + 1, n) mp[ar[i] + ar[j]] = {i, j};

   rep(i, 1, n) {
      rep(j, i + 1, n) {
         auto it = mp[x - ar[i] - ar[j]];
         if (it.ff && it.ff != i && it.ff != j && it.ss != i && it.ss != j) {
            cout << i << " " << j << " " << it.ff << " " << it.ss << "\n";
            return;
         }
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