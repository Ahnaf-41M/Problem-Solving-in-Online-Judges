#include<bits/stdc++.h>
#define  MX      205
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int Ok[MX + 5];
vector<int> primes;

void Sieve()
{
   for (int i = 3; i <= MX; i += 2)
      Ok[i] = 1;
   for (int i = 3; i <= MX; i += 2)
      if (Ok[i])
         for (int j = i * i; j <= MX; j += i)
            Ok[j] = 0;
   primes.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (Ok[i])
         primes.pb(i);
}
void Factorize(int n, map<int, int> &mp)
{
   int i = 0;
   while (i < primes.size() && primes[i]*primes[i] <= n) {
      int cnt = 0;
      while (n % primes[i] == 0)
         n /= primes[i], mp[primes[i]]++;
      i++;
   }
   if (n > 1)
      mp[n]++;
}
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   Sieve();
   int t;
   cin >> t;

   for (int k = 1; k <= t; k++) {
      int n, i = 0, n2;
      map<int, int> divCnt;

      cin >> n;

      for (int j = 2; j <= n; j++)
         Factorize(j, divCnt);

      cout << "Case " << k << ": " << n << " = ";

      for (auto it = divCnt.begin(); it != divCnt.end(); it++) {
         auto it2 = it;
         it2++;
         cout << it->ff << " (" << it->ss << ")";
         if (it2 != divCnt.end())
            cout << " * ";
      }
      cout << endl;
   }

   return 0;
}
