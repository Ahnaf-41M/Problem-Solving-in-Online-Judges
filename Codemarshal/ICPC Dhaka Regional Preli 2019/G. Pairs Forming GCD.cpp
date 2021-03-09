#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MX  10000005

int Phi[MX + 5], phiSum[MX + 5];

void Totient()
{
   for (int i = 1; i <= MX; i++)
      Phi[i] = i;
   for (int i = 2; i <= MX; i++)
      if (Phi[i] == i)
         for (int j = i; j <= MX; j += i)
            Phi[j] -= Phi[j] / i;
   
   //Presum of all the pairs with GCD(x,y)=1.(1 <= x <= y <= n)
   for (int i = 1; i <= MX; i++)
      phiSum[i] = phiSum[i - 1] + Phi[i];
}
int BSearch(int n, int p)
{
   //finding first index res with phiSum[res] >= p
   int res = -1, low = 1, high = n;

   while (low <= high) {
      int mid = (low + high) >> 1;
      if (phiSum[mid] >= p) {
         res = mid;
         high = mid - 1;
      }
      else
         low = mid + 1;
   }
   return res;
}
signed main()
{
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);

   Totient();
   int t;

   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {
      int n, p;
      scanf("%lld%lld", &n, &p);

      int ans = BSearch(n, p);
      ans = (ans == -1 ? ans : n / ans);
      printf("Case %lld: %lld\n", k, ans);
   }
}