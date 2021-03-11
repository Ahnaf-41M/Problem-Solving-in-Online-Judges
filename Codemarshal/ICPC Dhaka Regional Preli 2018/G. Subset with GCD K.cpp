#include<bits/stdc++.h>
#define ll   long long
#define endl  "\n"
using namespace std;
const int mx = 1e5;

int main()
{
   int n;
   cin >> n;

   int ar[n];
   for (int i = 0; i < n; i++)
      scanf("%d", &ar[i]);

   int q, k;

   cin >> q;

   while (q--) {
      cin >> k;
      int gg = 0;

      for (int i = 0; i < n; ++i) {
         if (ar[i] % k == 0) {
            gg = __gcd(ar[i], gg);
            if (gg == k)
               break;
         }
      }
      if (gg == k)
         printf("Y\n");
      else
         printf("N\n");
   }
   return 0;  

}