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

vector<int> primes;
bool is_prime[MX + 5];
int freq[MX + 5];

inline void sieve()
{
   for (int i = 3; i <= MX; i += 2)
      is_prime[i] = true;
   for (int i = 3; i <= sqrt(MX); i += 2)
      if (is_prime[i])
         for (int j = i * i; j <= MX; j += i)
            is_prime[j] = false;

   primes.pb(2);

   for (int i = 3; i <= MX; i += 2)
      if (is_prime[i])
         primes.pb(i);

}
void Factorize(int m)
{
   for (int i = 0; i < primes.size() && primes[i]*primes[i] <= m; i++) {
      while (m % primes[i] == 0) {
         m /= primes[i];
         freq[primes[i]]++;
      }
   }
   if (m > 1)
      freq[m]++;
}
void solve()
{
   sieve();
   int t, n;

   cin >> t;

   W(t)
   {
      cin >> n;
      int prod = 1;
      memset(freq, 0, sizeof(freq));
      bool ok = true;

      rep(i, 1, n) {
         int x; cin >> x;
         Factorize(x);
      }

      rep(i, 0, primes.size() - 1) {
         if (freq[primes[i]] & 1) {
            ok = false;
            break;
         }
      }
      cout << (ok ? "YES\n" : "NO\n");
   }

   return;
}
signed main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   solve();

   return 0;
}