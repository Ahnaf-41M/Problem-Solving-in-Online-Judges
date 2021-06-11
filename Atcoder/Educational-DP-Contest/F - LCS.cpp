#include "bits/stdc++.h"
#define  MX         100005
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  int        long long
#define  PII        pair<int,int>
#define  all(v)     v.begin(),v.end()
#define  rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

string s, t;
int n1, n2;
int dp[3005][3005];

int func(int x, int y)
{
   if (x >= n1 || y >= n2) return 0;
   if (dp[x][y] != -1) return dp[x][y];

   if (s[x] == t[y])
      return dp[x][y] = 1 + func(x + 1, y + 1);
   else {
      int r1 = func(x + 1, y);
      int r2 = func(x, y + 1);
      return dp[x][y] = max(r1, r2);
   }
}
void Print_LCS()
{
   int i = 0, j = 0;
   string lcs = "";
   while (i < n1 && j < n2) {
      if (s[i] == t[j]) {
         lcs += s[i];
         i++, j++;
      }
      else {
         if (dp[i + 1][j] > dp[i][j + 1]) i++;
         else j++;
      }
   }
   cout << lcs;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));

   cin >> s >> t;
   n1 = s.size(), n2 = t.size();

   func(0, 0);
   Print_LCS();
   return 0;
}