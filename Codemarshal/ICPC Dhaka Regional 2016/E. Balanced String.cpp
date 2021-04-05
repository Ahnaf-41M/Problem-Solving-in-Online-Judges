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

   int t;
   cin >> t;

   for (int k = 1; k <= t; k++) {
      map<int, int> mp;
      int n, mx = 0;
      cin >> n;

      for (int i = 1; i <= n; i++) {
         int x; cin >> x;
         mp[x]++; mx = max(mx, x);
      }

      cout << "Case " << k << ": ";
      if (n & 1 || (mx > n / 2))
         cout << "invalid\n";
      else {
         queue<char> cur;
         int j = 0, ok = 1;

         while (true) {
            if (mp[j + 1]) {
               cur.push('('), mp[j + 1]--;
               j++;
            }
            else if (mp[j - 1]) {
               cur.push(')'), mp[j - 1]--;
               j--;
            }
            else
               break;
         }
         if (cur.size() != n)
            cout << "invalid\n";
         else {
            while (!cur.empty())
               cout << cur.front(), cur.pop();
            cout << "\n";
         }
      }

   }

   return 0;
}