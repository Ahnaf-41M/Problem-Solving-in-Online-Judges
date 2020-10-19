#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define ll long long

ll phi[MAX];
ll s[MAX];

void pre_calculation()
{
     int i,j;

     /*Eular Totient using Inclusion-Exclusion*/
     for(i = 1; i <= MAX-5; i++)
          phi[i] = i;

     for(i = 2; i <= MAX-5; i++)
     {
          if(phi[i]==i)
          {
               for(j = i; j <= MAX-5; j+=i)
               {
                    phi[j] -= phi[j]/i;
               }
          }
     }

     /*Finding gcd and adding them for every n from 1 to n..*/
     for(i = 1; i <= MAX-5; i++)
     {
          for(j = i+i; j <= MAX-5; j+=i)
          {
               s[j] = s[j] +(ll) (i*phi[j/i]);
          }
     }

     /*Prefix sum for every pair of gcd up to n..*/

     for(i = 2; i <= MAX-5; i++)
          s[i] = s[i] + s[i-1];

}
int main()
{
    pre_calculation();

    int n;

    while(scanf("%d",&n) && n!=0)
    {
         printf("%lld\n",s[n]);
    }
}
