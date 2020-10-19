#include <bits/stdc++.h>
using namespace std;

int n, query, sq;
vector<vector<int> > tab;

void BuildTable()
{
   for (int j = 1; j <= sq; j++)
      for (int i = 0; i + (1 << j) - 1 < n; i++)
         tab[i][j] = max(tab[i][j - 1], tab[i + (1 << (j - 1))][j - 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n >> query;
   sq = log2(n);
   int a[n];
   tab.assign(n + 1, vector<int>(sq + 1));

   for (int i = 0; i < n; i++) {
      cin >> a[i];
      tab[i][0] = a[i];
   }
   BuildTable();
   int ans = 0;

   while (query--)
   {
      int A, B; cin >> A >> B;
      A--; B--;

      if (A <= B)
      {
         B--;
         int j = log2(B - A + 1);
         if (a[A] >= max(tab[A][j], tab[B - (1 << j) + 1][j]))
            ans++;
      }
      else
      {
         B++;
         int j = log2(A - B + 1);
         if (a[A] >= max(tab[B][j], tab[A - (1 << j) + 1][j]))
            ans++;
      }
   }
   cout << ans << endl;

}