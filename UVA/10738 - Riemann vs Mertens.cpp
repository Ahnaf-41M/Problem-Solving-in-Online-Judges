#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 1000005
#define mx 1000
bool a[mx];
vector<int> v;
int M[Max];   /*for Mertens's function*/
int mu[Max]; /*for Mobius function*/
void sieve()
{
    int i,j;
    a[0]=0,a[1]=0,a[2]=1;

    for(i = 3; i <= mx; i+=2)
        a[i]=1;
    for(i = 3; i <= sqrt(mx); i++)
    {
        if(a[i])
        {
            for(j = i*i; j <= mx; j+=i)
            {
                a[j]=0;
            }
        }
    }
    v.push_back(2);
    for(i = 3; i <= mx; i+=2)
        if(a[i])
            v.push_back(i);
}
void Mertens_Mobius_function()
{
     int i,j,n,cnt=0;
     M[1] = 1;
     mu[1] = 1;
     for(i = 2; i < Max; i++)
     {
          n = i;
          cnt=0;
          for(j = 0; v[j]*v[j] <= n, j<v.size(); j++)
          {
               if(n%v[j] == 0)
               {
                    cnt++;

                    if((n/v[j])%v[j] == 0)
                    {
                         cnt = -100;
                         break;
                    }
                    n/=v[j];
               }
          }
          if(n!=1)
               cnt++;
          if(cnt < 0)
          {
               /*if N is not square free,mu(N) = 0(means it contains at least 2 same prime factor.. */
               mu[i] = 0;
               M[i] = M[i-1]+mu[i];
          }
          else
          {
               if(cnt&1)
                    mu[i] = -1; /*if N is square free and contains an odd number of prime factors,mu(N) = -1*/
               else
                    mu[i] = 1; /*if N is square free and contains an even number of prime factors,mu(N) = 1*/

               M[i] = M[i-1] + mu[i];
          }
     }
}
int main()
{
    int i,j,n;
    sieve();
    Mertens_Mobius_function();

    while(scanf("%d",&n) && n>0)
    {
         printf("%8d%8d%8d\n",n,mu[n],M[n]);
    }


    return 0;
}
