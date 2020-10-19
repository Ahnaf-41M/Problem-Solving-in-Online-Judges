#include <bits/stdc++.h>
#define ll long long
using namespace std;
//using namespace __gnu_cxx;

int main()
{
     //IOS
     ll n, i;
     int t;
     bool f = true;

     scanf("%d", &t);

     while (t--)
     {
          scanf("%lld", &n);
          f = true;
          ll s = sqrt(n);

          for (i = 2; i <= s; i++)
          {
               if (n % i == 0)
               {
                    f = false;
                    break;
               }
          }

          if (f && n>1)
               printf("YES\n");
          else
               printf("NO\n");
     }
}