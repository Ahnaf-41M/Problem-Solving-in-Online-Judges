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
#define mod 1000000007
#define mx 1000000
using namespace std;
ll fact[mx+1];

void factorial()
{
     ll i;
     fact[0]=1,fact[1]=1;

     for(i = 2; i <= mx; i++)
          fact[i] = (i*fact[i-1])%mod;
}
ll ModExponent(ll a,ll b)
{
     ll res = 1;

     while(b>0)
     {
          if(b&1)
               res = (res*a)%mod;
          a = (a*a)%mod;
          b/=2;
     }
     return res;
}
int main()
{
     IOS
     factorial();
     int t,i;
     string s;

     ll len,n;

     cin>>t;

     while(t--)
     {
          cin>>s;
          len = s.size();
          map<ll,ll> unq;

          for(i = 0; i < len; i++)
               unq[s[i]-'0']++;

          ll ans = fact[len];

          for(ll i = 0; i <= 9; i++)
          {
               ans = (ans*ModExponent(fact[unq[i]],mod-2))%mod;
          }
          cout<<ans<<endl;

     }
     return 0;
}

