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

vector<ll> primes;
vector<ll> humbles;
void humble_numbers()
{
     ll i,j,n;

     primes.pb(2);
     primes.pb(3);
     primes.pb(5);
     primes.pb(7);
     humbles.pb(1);

     for(i = 2; i <= 9999999; i++)
     {
          n=i;

          for(j = 0; primes[j] < n,j<4; j++)
          {
               while(n%primes[j]==0)
               {
                    n/=primes[j];
               }
          }
          if(n==1)
               humbles.pb(i);
     }
     for(i = 10000000; i <= 2000000000; i++)
     {
          n=i;

          for(j = 0; primes[j] < n,j<4; j++)
          {
               while(n%primes[j]==0)
               {
                    n/=primes[j];
               }
          }
          if(n==1)
               humbles.pb(i);
     }
}
int main()
{
     IOS
     humble_numbers();
     ll n,i;

     cin>>n;
     cout<<humbles[n-1];


     return 0;
}

