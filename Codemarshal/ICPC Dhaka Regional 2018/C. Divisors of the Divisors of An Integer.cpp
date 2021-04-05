#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

bitset < MX + 5 > OK;
vector<int> primes;
const int MOD = 1e7 + 7;

void Sieve()
{
   for (int i = 3; i <= MX; i += 2)
      OK[i] = 1;
   for (int i = 3; i * i <= MX; i += 2)
      if (OK[i])
         for (int j = i * i; j <= MX; j += i)
            OK[j] = 0;
   primes.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (OK[i])
         primes.pb(i);
}
int Solve(int n)
{
   int res = 1;
   for (int x : primes) {
      int cnt = 1, m = n;
      if (n < x)
         break;
      while (m)
         m /= x, cnt += m;
      cnt = (cnt * (cnt + 1)) / 2;
      res = (res % MOD) * (cnt % MOD);
   }
   return res % MOD;
}
signed main()
{
   // ios::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);

   Sieve();
   
   int n;
   while (scanf("%lld", &n) && n)
      printf("%lld\n", Solve(n));

   return 0;
}