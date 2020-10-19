#include<bits/stdc++.h>
using namespace std;

#define mx 1000000
int a[mx];

void sieve()
{
   int i, j;
   a[2] = 1;
   for (i = 3; i <= mx; i += 2)
      a[i] = 1;
   for (i = 2; i <= sqrt(mx); i++)
   {
      if (a[i] == 1)
      {
         for (j = 2; i * j <= mx; j++)
         {
            a[i * j] = 0;
         }
      }
   }

}
int main()
{
   sieve();

   int n;

   while (scanf("%d", &n) && n > 0)
   {
      for (int i = n - 1; i >= 2; i--)
      {
         if (a[i] == 1 && a[n - i] == 1) {
            printf("%d = %d + %d\n", n, n - i, i);
            break;
         }
      }
   }
}
