#include<bits/stdc++.h>
#define  MX      3000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long int
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

unsigned int phi[MX + 5], res[MX + 5];

void ETF()
{
   for (int i = 1; i <= MX; i++)
      phi[i] = i;
   for (int i = 2; i <= MX; i++)
      if (phi[i] == i)
         for (int j = i; j <= MX; j += i)
            phi[j] -= phi[j] / i;
}
void Pre_Compute()
{
   res[1] = 0;

   /* Below part is for Sum of LCM(1,n)+LCM(2,n)+...+LCM(n-1,n) */
   for (unsigned int i = 2; i <= MX; i++) {
      /* 2*Sum = n * (∑ ϕ(d)*d) + n. But we are not considering
        LCM(n,n) in our sum, we will exlclude n from the equation.
        Hence, 2*Sum = n * (∑ ϕ(d)*d)
            => Sum = n * (∑ ϕ(d)*d)/2  */
      for (unsigned int j = i; j <= MX; j += i) {
         res[j] += phi[i] * i; //ϕ(d)*d part
      }
      res[i] /= 2; // (∑ ϕ(d)*d)/2 part
      res[i] *= i; // n * (∑ ϕ(d)*d)/2 part
   }

   /* Pre-summing the res, we will get our answer for every pair. */
   for (unsigned int i = 2; i <= MX; i++)
      res[i] += res[i - 1];
}
signed main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   ETF();
   Pre_Compute();

   int t;
   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {
      int n;
      scanf("%lld", &n);
      printf("Case %lld: %llu\n", k, res[n]);
   }
   return 0;
}