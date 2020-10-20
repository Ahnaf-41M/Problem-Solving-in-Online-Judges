#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 1000005
bool a[Max+10];

void seive()
{
   int i, j;
   a[2] = 1;

   for (i = 3; i <= Max; i += 2)
      a[i] = 1;
   for (i = 3; i <= sqrt(Max); i+=2)
      if (a[i] == 1)
         for (j = i*2; j <= Max; j+=i)
            a[j] = 0;

}
int main()
{
   ll i, j, n, t;
   seive();
   cin >> t;
   while (t--)
   {
      cin >> n;
      if (a[n]||n==1)
         cout << "No\n";
      else
         cout << "Yes\n";
   }

   return 0;
}