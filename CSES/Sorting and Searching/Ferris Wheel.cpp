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

   int n, x, ans = 0;

   cin >> n >> x;
   vector<int> v(n);

   for (int &e : v)
      cin >> e;
   sort(all(v));

   int i = 0, j = n - 1;
   while (i <= j) {
      if (v[i] + v[j] <= x) {
         ans++;
         i++, j--;
      }
      else{
         ans++;
         j--;
      }
   }
   cout << ans;
   return 0;
}