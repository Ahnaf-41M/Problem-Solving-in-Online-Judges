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

int T, N;
int bit[21];
void Solve()
{
   int X;
   cin >> X;

   rep(i, 0, 20) {
      if ((1 << i) & X)
         bit[i]++;
   }
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int ans = 0;
   cin >> N;
   T = N;

   W(T)
   {
      Solve();
   }

   rep(i, 0, 20) {
      ans += (bit[i] * (N - bit[i])) * (1 << i);
   }
   cout << ans;
   return 0;
}