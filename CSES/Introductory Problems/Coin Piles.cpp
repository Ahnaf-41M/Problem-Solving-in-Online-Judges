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

   int n; cin >> n;
   while (n--) {
      int a, b; cin >> a >> b;
      if ((a + b) % 3 == 0 && 2 * min(a, b) >= max(a, b))
         cout << "YES\n";
      else
         cout << "NO\n";
   }

   return 0;
}