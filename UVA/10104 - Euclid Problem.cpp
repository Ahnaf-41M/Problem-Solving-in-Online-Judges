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

int Extended_gcd(int a, int b, int &x, int &y)
{
   if (b == 0) {
      x = 1;
      y = 0;
      return a;
   }
   int x1, y1;
   int d = Extended_gcd(b, a % b, x1, y1);

   x = y1;
   y = x1 - y1 * (a / b);

   return d;
}
void solve()
{
   int a, b;

   while (cin >> a >> b)
   {
      int x, y, d;
      d = Extended_gcd(a, b, x, y);
      cout << x << " " << y << " " << d << endl;
   }

   return;
}
signed main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   solve();

   return 0;
}
