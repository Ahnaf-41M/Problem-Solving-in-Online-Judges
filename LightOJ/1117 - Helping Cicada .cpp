#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)
#define  irep(i,a,b)     for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

int solve()
{
   int n, m;
   scanf("%lld%lld", &n, &m);
   int a[m + 1];

   rep(i, 0, m - 1) scanf("%lld", &a[i]);

   int tot = (1 << m) - 1, sum = 0;

   rep(i, 1, tot) {
      int cnt = 0, cur_lcm = 1;

      rep(j, 0, m - 1) {
         if (i & (1 << j)) {
            cnt++;
            cur_lcm = lcm(a[j], cur_lcm);
         }
      }

      if (cnt & 1)
         sum += (n / cur_lcm);
      else
         sum -= (n / cur_lcm);
   }
   return n - sum;
}
signed main()
{
   int t;
   scanf("%lld", &t);

   rep(k, 1, t) {
      int res = solve();
      printf("Case %lld: %lld\n", k, res);
   }

   return 0;
}