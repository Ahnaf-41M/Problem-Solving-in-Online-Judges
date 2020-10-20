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
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
const int mx = 1e6;
bool is_prime[mx+5];
int pre[mx+5];

inline void sieve()
{
    int i,j;

    is_prime[2] = true;
    pre[1]=1;

    for(i = 3; i <= mx; i+=2)
        is_prime[i] = true;
    for(i = 2; i <= sqrt(mx); i++)
    {
        if(is_prime[i])
        {
            for(j = i*i; j <= mx; j+=i)
                is_prime[j] = false,pre[j]=1;;
        }
    }
    pre[4] = 0;

    for(i = 1; i <= mx; i++)
        pre[i]+=pre[i-1];
}
int main()
{
    IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();

    int t,l,r;
    cin>>t;

    W(t)
    {
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }

    return 0;
}

