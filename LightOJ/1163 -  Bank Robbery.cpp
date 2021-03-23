#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int Val(int A)
{
   return A - (A / 10);
}
void BSearch(set<int> &v, int n)
{
   int low = n, high = n + 1e18, n2 = n;

   while (low <= high) {
      int mid = (low + high) >> 1;
      if (Val(mid) == n) {
         v.insert(mid);
         if (Val(mid + 1) == n)
            v.insert(mid + 1);
         else if (Val(mid - 1) == n)
            v.insert(mid - 1);
         break;
      }
      if (Val(mid) <= n)
         low = mid + 1;
      else
         high = mid - 1;
   }
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   int t;
   cin >> t;

   for (int k = 1; k <= t; k++) {
      int n;
      cin >> n;
      set<int> ans;
      BSearch(ans, n);

      cout << "Case " << k << ": ";

      // reverse(all(ans));
      for (auto it = ans.begin(); it != ans.end(); it++) {
         auto it2 = it;
         it2++;
         cout << *it ;
         if (it2 != ans.end())
            cout << " ";
      }
      cout << endl;
   }
   return 0;
}