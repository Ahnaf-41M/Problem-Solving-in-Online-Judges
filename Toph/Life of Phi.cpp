#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int phi[MX + 5];

void Totient()
{
   for (int i = 1; i <= MX; i++)
      phi[i] = i;
   for (int i = 2; i <= MX; i++)
      if (phi[i] == i)
         for (int j = i; j <= MX; j += i)
            phi[j] -= phi[j] / i;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   Totient();
   int t;
   cin >> t;

   while ( t-- ) {
      int n, ans, sumOfCoprimes;
      cin >> n;

      sumOfCoprimes = (phi[n] * n) / 2; //sum of integers co-prime to n
      ans = (n * (n + 1)) / 2 - sumOfCoprimes - n; //from 1 to n-1
      cout << ans << endl;
   }

   return 0;
}