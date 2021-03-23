#include<bits/stdc++.h>
#define  MX      10000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

bitset < MX + 5 > isPrime;
vector<int> primes;
void Sieve()
{
   for (int i = 3; i <= MX; i += 2)
      isPrime[i] = 1;
   isPrime[2] = 1;
   for (int i = 3; i*i <= MX; i += 2)
      if (isPrime[i])
         for (int j = i * i; j <= MX; j += i)
            isPrime[j] = 0;
   primes.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (isPrime[i])
         primes.pb(i);
}
signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);

   Sieve();
   int t;
   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {
      int n;

      scanf("%lld", &n);

      int ans = 0;
      for (int x : primes) {
         if (x > n / 2)
            break;
         if (isPrime[n - x]) 
            ans++;
      }
      printf("Case %lld: %d\n", k, ans);
   }
   return 0;
}
