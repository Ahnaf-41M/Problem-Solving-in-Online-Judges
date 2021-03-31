#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int n, ans;
int a[12][12];

void Check1()
{
   for (int i = 1; i <= n - 1; i++) {
      for (int j = 1; j <= n; j++) {
         map<int, int> mp;
         int k = j;
         while (k <= j + 4) {
            if (mp[a[i][k]] || mp[a[i + 1][k]])
               break;
            mp[a[i][k]] = mp[a[i + 1][k]] = 1;
            k++;
         }
         ans = (mp.size() == 10 ? ans + 1 : ans);
      }
   }
}
void Check2()
{
   for (int j = 1; j <= n - 1; j++) {
      for (int i = 1; i <= n; i++) {
         map<int, int> mp;
         int k = i;
         while (k <= i + 4) {
            if (mp[a[k][j]] || mp[a[k][j + 1]])
               break;
            mp[a[k][j]] = mp[a[k][j + 1]] = 1;
            k++;
         }
         ans = (mp.size() == 10 ? ans + 1 : ans);
      }
   }
}
void Check3()
{
   for (int i = 1; i <= n; i++) {
      map<int, int> mp;
      for (int j = 1; j <= n; j++) {
         if (mp[a[i][j]])
            break;
         mp[a[i][j]]++;
      }
      ans = (mp.size() == 10 ? ans + 1 : ans);
   }
   for (int j = 1; j <= n; j++) {
      map<int, int> mp;
      for (int i = 1; i <= n; i++) {
         if (mp[a[i][j]])
            break;
         mp[a[i][j]]++;
      }
      ans = (mp.size() == 10 ? ans + 1 : ans);
   }
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int t; cin >> t;

   for (int k = 1; k <= t; k++) {
      cin >> n;
      for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
            cin >> a[i][j];
      cout << "Case " << k << ": ";
      if (n < 5) cout << "0\n";
      else {
         ans = 0;
         if (n == 10)
            Check3();
         Check1();
         Check2();
         cout << ans << "\n";
      }
   }
   return 0;
}