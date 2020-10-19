#include<bits/stdc++.h>
using namespace std;
#define IOS  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

void LCS(string s1, string s2, int n, int m)
{
   int dp[n + 1][m + 1] = {};
   string ans[n + 1][m + 1] = {};
   int i, j;

   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= m; j++)
      {
         if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
            ans[i][j] = ans[i - 1][j - 1] + s1[i - 1];
         }
         else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
               dp[i][j] = dp[i - 1][j];
               ans[i][j] = ans[i - 1][j];
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
               dp[i][j] = dp[i][j - 1];
               ans[i][j] = ans[i][j - 1];
            }
            else {
               //take the lexicographically smallest string
               ans[i][j] = min(ans[i][j - 1], ans[i - 1][j]);
               dp[i][j] = dp[i - 1][j];
            }
         }
      }
   }

   if (dp[n][m] == 0)
      cout << ":(" << endl;
   else
      cout << ans[n][m] << endl;
}
int main()
{
   int n, m, t;
   string s1, s2;

   cin >> t;

   for (int i = 1; i <= t; i++)
   {
      cin >> s1 >> s2;
      n = s1.size();
      m = s2.size();

      cout << "Case " << i << ": ";

      LCS(s1, s2, n, m);
   }
}
