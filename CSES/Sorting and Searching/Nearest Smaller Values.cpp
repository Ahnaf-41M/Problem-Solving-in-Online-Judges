/*Reverse the question. Traverse the array from the right and find for each index i how many
  values to its right are greater than ar[i].*/
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

int ans[2 * MX], ar[2 * MX];
void Solve(int tc)
{
   int n;
   multiset<PII> S;

   cin >> n;

   rep(i, 1, n) cin >> ar[i];
   irep(i, n, 1) {
      if (S.empty()) S.insert({ar[i], i});
      else {
         while (!S.empty()) {
            auto it = S.upper_bound({ar[i], 1e10});
            if (it == S.end()) break;
            ans[it->ss] = i;
            S.erase(it);
         }
         S.insert({ar[i], i});
      }
   }
   rep(i, 1, n) cout << ans[i] << " ";
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