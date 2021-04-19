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

int CountDivs(int n)
{
   int ans = 1;

   int cnt = 0;

   while (n % 2 == 0)
      cnt++, n /= 2;
   ans *= (cnt + 1);

   for (int i = 3; i * i <= n; i += 2) {
      cnt = 0;
      while (n % i == 0)
         cnt++, n /= i;
      ans *= (cnt + 1);
   }
   if (n > 1)
      ans *= 2;
   return ans;
}
void Solve()
{
   int n;
   cin >> n;

   cout << CountDivs(n) << endl;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;

   while (T--)
      Solve();

   return 0;
}