#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            10000005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

int MOD = 1e9 + 7;
vector<int> tot;
int N, lp[MX], frq1[MX], frq2[MX];

void Sieve()
{
   lp[1] = 1;
   for (int i = 2; i < MX; i++) {
      if (!lp[i]) {
         lp[i] = i;
         for (int j = i * i; j < MX; j += i)
            lp[j] = i;
      }
   }
}
void Factorize(int x, int k)
{
   while (x > 1) {
      int cnt = 0;
      int prime = lp[x];
      while (x % prime == 0)
         cnt++, x /= prime;
      if (cnt) {
         if (k == 1) {
            if (!frq1[prime]) tot.pb(prime);
            frq1[prime] += cnt;
         }
         else frq2[prime] += cnt;
      }
   }
}
int BigMod(int a, int p) //calculate a^p
{
   int res = 1;
   while (p) {
      if (p & 1)
         res = res * a % MOD;
      a = a * a % MOD;
      p >>= 1;
   }
   return res;
}
void Solve(int k)
{
   int M; cin >> M;
   while (M--) {
      int x; cin >> x;
      Factorize(x, k);
   }
   if (k > 1) {
      for (int cur : tot) {
         frq1[cur] = min(frq1[cur], frq2[cur]);
         frq2[cur] = 0;
      }
   }
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   Sieve();

   cin >> N;

   rep(i, 1, N) {
      Solve(i);
   }

   int ans = 1;
   for (int x : tot) {
      int pp = frq1[x];
      ans = (ans * BigMod(x, pp)) % MOD;
   }
   cout << ans << "\n";
   return 0;
}