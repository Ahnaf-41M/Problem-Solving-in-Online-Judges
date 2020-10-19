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
using namespace std;
int main()
{
     IOS
     ll t,n;
     cin>>t;

     while(t--)
     {
          ll ans=0;
          cin>>n;
          ll a[n];
          ll pref_sum[n];
          rep1(n)
          {
               cin>>a[i];
               if(i==0)
                    pref_sum[i] = a[i];
               else
                    pref_sum[i] = a[i] + pref_sum[i-1];
          }
          map<ll,ll> freq;
          map<ll,ll>::iterator it;

          rep1(n)
          {
               freq[pref_sum[i]]++;
          }
          for(it = freq.begin(); it != freq.end(); it++)
          {
               ll x = it->first;
               ll y = it->second;

               if(x != 0)
                    ans += y*(y-1)/2;
               else
                    ans += y*(y-1)/2 + y;
          }
          cout<<ans<<endl;
     }

     return 0;
}

