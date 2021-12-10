#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           3000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

double fact[MX];

void Solve(int tc)
{
   int a;
   cin >> a;

   int l = 1, h = 3e6, n;
   while (l <= h) {
      int mid = (l + h) >> 1;
      double fc = fact[mid];
      double pwr = (double)(mid) * (log10((double)a));
      if (fc > pwr) {
         n = mid;
         h = mid - 1;
      }
      else l = mid + 1;
   }
   cout << n << "\n";
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   rep(i, 2, MX - 1) fact[i] = fact[i - 1] + log10((double)i);

   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}