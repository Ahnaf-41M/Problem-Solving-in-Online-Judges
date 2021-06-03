/*First we will find LIS and LDS for each index 'i'. Then, after
  choosing an 'i', we can either add a car in the end (decreasing) or 
  in the begining(increasing).Hence our answer will be LIS+LDS-1.
  -1 for considering car twice in the answer. */
#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           1005
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  gcd(a,b)     __gcd(a,b)
#define  lcm(a,b)     (a*b)/gcd(a,b)
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int n, dp1[2 * MX], dp2[2 * MX];
void LIS(int ar[]) //Increasing Subsequence
{
   irep(i, n - 1, 0) {
      dp1[i] = 1;
      rep(j, i + 1, n - 1) {
         if (ar[i] < ar[j])
            dp1[i] = max(dp1[j] + 1, dp1[i]);
      }
   }
   return;
}
void LDS(int ar[]) //Decreasing Subsequence
{
   irep(i, n - 1, 0) {
      dp2[i] = 1;
      rep(j, i + 1, n - 1) {
         if (ar[i] > ar[j])
            dp2[i] = max(dp2[j] + 1, dp2[i]);
      }
   }
   return;
}
void Solve(int tc)
{
   cin >> n;
   int ar[n];

   for (int &x : ar) cin >> x;
   LIS(ar);
   LDS(ar);

   int ans = 0;
   rep(i, 0, n - 1) ans = max(dp1[i] + dp2[i] - 1, ans);
   cout << ans << "\n";
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}