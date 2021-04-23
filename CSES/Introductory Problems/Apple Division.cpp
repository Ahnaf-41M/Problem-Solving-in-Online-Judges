#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, ans = INT_MAX;
   cin >> n;
   int ar[n];

   for (int i = 0; i < n; i++) 
      cin >> ar[i];

   for (int i = 1; i < (1 << n); i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
         if (i & (1 << j))
            cur += ar[j];
         else 
            cur -= ar[j];
      }
      ans = min(ans, abs(cur));
   }
   cout << ans;
   return 0;
}