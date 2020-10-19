#include<bits/stdc++.h>

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define PI M_PI
#define endl "\n"
#define sc scanf
#define pf printf
#define ll long long
#define ull unsigned long long
#define rep1(n)   for(int i = 0; i < n; i++)
#define rep2(a,b) for(int i = a;i <= b; i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mx 10000000
using namespace std;

bool a[mx+5];
int pre_sum[mx+5];
void sieve()
{
     int i,j;

     a[2] = true;
     for(i = 3; i <= mx; i+=2)
          a[i] = true;

     for(i = 3; i <= sqrt(mx); i+=2)
     {
          if(a[i])
          {
               for(j = i*i; j <= mx; j+=i)
               {
                    a[j] = false;
               }
          }
     }
     for(i = 2; i <= mx; i++)
     {
          if(a[i])
               pre_sum[i] = pre_sum[i-1] +1;
          else
               pre_sum[i] = pre_sum[i-1];
     }
}
int main()
{
     IOS
     sieve();

     int t,n;

     sc("%d",&t);

     while(t--)
     {
          sc("%d",&n);
          pf("%d\n",pre_sum[n] - pre_sum[n/2]);
     }

     return 0;
}

