#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

int indeg[2 * MX], has[2 * MX];

void Solve()
{
   set<int> cur;
   int n, ans = 0;

   cin >> n;
   rep(i, 1, n) {
      int x; cin >> x;
      if (has[x - 1])
         indeg[x]++;
      has[x]++;
   }

   rep(i, 1, n) ans += (indeg[i] == 0);
   cout << ans;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   //int T;
   //cin >> T;

   //while (T--)
   Solve();

   return 0;
}