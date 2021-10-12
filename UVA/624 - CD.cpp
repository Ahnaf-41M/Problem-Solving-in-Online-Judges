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

int n, trks;
void Solve(int tc)
{
   while (cin >> n >> trks) {
      vector<int> ans;
      int ar[trks], curN = n, sum = 0;

      for (int &x : ar) cin >> x;

      for (int i = 0; i < (1 << trks); i++) {
         int curSum = 0;
         vector<int> curV;
         for (int j = 0; j < trks; j++) {
            if ((i & (1 << j))) {
               curV.pb(ar[j]);
               curSum += ar[j];
            }
         }
         if (curSum <= n && sum < curSum) {
            sum = curSum;
            ans = curV;
         }
      }
      for (int x : ans) cout << x << " ";
      cout << "sum:" << sum << "\n";
   }
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}