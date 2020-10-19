#include<bits/stdc++.h>
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  /*Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)*/
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define ll long long
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
     ll t,i,j,n,m;
     vector<ll> v;
     cin>>t;

     for(i = 1; i <= t; i++)
     {
          cin>>n;
          m = n;
          while(m>=2)
          {
               v.pb(m%2);
               m/=2;
          }
          v.pb(m);
          v.pb(0);
          reverse(v.begin(),v.end());
          next_permutation(v.begin(),v.end());

          ll sz = v.size();
          ll ep = sz-1;
          ll ans=0;

          for(j = 0; j < sz; j++)
          {
               if(v[j]!=0)
                    ans+=(ll)pow(2,ep);
               ep--;
          }
          printf("Case %lld: %lld\n",i,ans);
          v.clear();
     }

}
