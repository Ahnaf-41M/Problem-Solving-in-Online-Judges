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

   int n, m;
   multiset<int> price;

   cin >> n >> m;

   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      price.insert(x);
   }

   for (int i = 0; i < m; i++) {
      int x; cin >> x;
      if (!price.empty()) {
         auto it = price.upper_bound(x);
         if (it != price.begin())
            it--;
         if (*it <= x) {
            cout << *it << "\n";
            price.erase(it);
         }
         else
            cout << "-1\n";
      }
      else
         cout << "-1\n";
   }
   return 0;
}