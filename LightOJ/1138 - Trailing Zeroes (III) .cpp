#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int n, m;

int trail_zeroes(int x)
{
   int cnt = 0;
   while (x) {
      cnt += x / 5;
      x /= 5;
   }
   return cnt;
}
int BSearch()
{
   int low = 5, high = m, res = -1;

   while (low <= high) {
      int mid = (low + high) / 2;
      int tot_0 = trail_zeroes(mid);
      if (tot_0 == n)
         res = mid;
      if (tot_0 >= n)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int t;
   cin >> t;

   for (int k = 1; k <= t; k++) {
      cin >> n;
      m = n * 5;
      int ans = BSearch();

      cout << "Case " << k << ": ";
      if (ans == -1)
         cout << "impossible\n";
      else
         cout << ans << "\n";
   }

   return 0;
}
