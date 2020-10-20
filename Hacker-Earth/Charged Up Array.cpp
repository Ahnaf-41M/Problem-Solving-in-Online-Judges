#include<bits/stdc++.h>
#include <ext/rope>

#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))

#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)    __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)       __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)       __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define PI   M_PI
#define endl "\n"
#define sc   scanf
#define pf   printf

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep1(i,n)       for(int i = 0; i < n; i++)
#define rep2(a,b)       for(int i = a; i <= b; i++)
#define rep3(a,b,c)     for(int i = a; i <= b; i+=c)
#define irep(a,b,c)     for(int i = b; i >=a; i-=c)
#define repit(it,type)  for(it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
const int mod = 1e9+7;
int main()
{
    IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,t,i;

    vector<ll> v;
    v.pb(0);

    for(i = 0; i <= 62; i++)
    {
        //cout<<(1ll<<i)<<endl;
        v.pb(1ll<<i);
    }
    cin>>t;

    W(t)
    {
        cin>>n;
        ll a[n],ans=0;
        rep1(i,n)
        {
            cin>>a[i];
        }
        if(n>63)
            cout<<0<<endl;
        else
        {
            rep1(i,n)
            {
                if(a[i]>=v[n])
                {
                    ans = (ans%mod+a[i]%mod)%mod;
                }
            }
            cout<<ans<<endl;
        }

    }

    return 0;
}

