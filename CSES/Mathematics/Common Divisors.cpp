#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            1000005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

int has[MX + 5];
void Solve()
{
   int n;
   cin >> n;

   rep(i, 0, n - 1) {
      int x; cin >> x;
      has[x]++;
   }
   int ans = 1;
   rep(i, 2, MX) {
      int cnt = 0;
      for (int j = i; j <= MX; j += i) {
         cnt += has[j];
         if (cnt > 1)
            break;
      }
      if (cnt > 1)
         ans = i;
   }
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