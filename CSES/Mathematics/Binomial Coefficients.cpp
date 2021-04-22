#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  MOD     1000000007
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int fact[MX];

void Work()
{
   fact[0] = fact[1] = 1;
   for (int i = 2; i < MX; i++)
      fact[i] = i * fact[i - 1] % MOD;
}
int Power(int a, int p)
{
   int res = 1;
   while (p) {
      if (p & 1) res = res * a % MOD;
      a = a * a % MOD;
      p >>= 1;
   }
   return res;
}
signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);

   Work();
   int n;
   scanf("%lld", &n);

   while (n--) {
      int a, b; scanf("%lld%lld", &a, &b);
      int ans = fact[a];
      ans = ans % MOD * Power(fact[b], MOD - 2) % MOD * Power(fact[a - b], MOD - 2) % MOD;
      printf("%lld\n", ans);
   }

   return 0;
}