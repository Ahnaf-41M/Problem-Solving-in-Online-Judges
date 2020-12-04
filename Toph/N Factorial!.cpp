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

int fact[21];

void pre_cal()
{
   int cur = 1;
   fact[0] = 1;
   rep(i, 1, 19) {
      cur *= i;
      fact[i] = cur;
   }
}
void solve()
{
   pre_cal();
   int t;

   cin >> t;

   W(t)
   {
      int n;
      cin >> n;
      if (n <= 19)
         printf("%04lld\n", fact[n] % 10000);
      else
         printf("0000\n");

   }

   return;
}
signed main()
{
   // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   solve();

   return 0;
}