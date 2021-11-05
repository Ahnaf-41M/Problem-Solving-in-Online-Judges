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

int ar[2 * MX], n, sum, ans;
map<int, int> prevSum;

void Solve(int tc)
{
   int cur = 0;
   cin >> n >> sum;
   rep(i, 1, n) cin >> ar[i];
   rep(i, 1, n) {
      cur += ar[i];
      ans += (cur == sum);
      ans += prevSum[cur - sum];
      prevSum[cur]++;
   }
   cout << ans;
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