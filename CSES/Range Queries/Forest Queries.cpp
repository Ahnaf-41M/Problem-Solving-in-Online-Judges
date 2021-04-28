#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int grid[1005][1005], pref[1005][1005];

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, m, q;
   cin >> n >> q;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         char ch; cin >> ch;
         grid[i][j] = (ch == '*' ? 1 : 0);
      }
   }
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
         pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
   while (q--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      cout << pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1] << "\n";
   }
   return 0;
}