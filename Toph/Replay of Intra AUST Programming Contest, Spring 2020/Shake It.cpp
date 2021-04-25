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

int dp[50];
void Work()
{
   dp[0] = dp[1] = 1;
   for (int i = 2; i <= 33; i++) {
      for (int j = 0; j < i; j++) {
         dp[i] += dp[j] * dp[i - j - 1];
      }
   }
}
void Solve()
{
   int s;
   cin >> s;
   while (s--) {
      int n; cin >> n;
      cout << dp[n] << endl;
   }
   cout << "\n";
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   Work();
   int T;
   cin >> T;

   while (T--)
      Solve();

   return 0;
}