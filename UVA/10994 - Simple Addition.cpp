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
#define ll long long
#define pb push_back
#define PI M_PI
#define endl "\n"
#define sc scanf
#define pf printf
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll F(ll n)
{
     ll res=0,x;

     while(n)
     {
          res += (n/10)*45; /*for every 10 sum from 1..9 is 45*/

          x = (n/10)*10;
          if(x<=n) /*if the number got remainder(like number 32,2 is a remainder), we should check..*/
          {
               x = n-x;
               res+= x*(x+1)/2; /*consider the number 32, remainder is 2 and sum of 1..2*/
          }
          n/=10;
     }
     return res;
}

int main()
{
     IOS
     ll p,q,i,ans;

     while(scanf("%lld%lld",&p,&q) && p>=0 &&q>=0)
     {
          ans=0;

          printf("%lld\n",F(max(p,q))-F(min(p,q)-1));
     }

     return 0;
}

