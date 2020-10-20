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
#define mx 1000005
using namespace std;

ll a[mx];

void sieve()
{
    int i,j;
    a[2]=1;
    for(i = 3; i <= mx; i+=2)
        a[i] = 1; //as even numbers can't be prime

    for(i = 2; i <= sqrt(mx); i++)
    {
        if(a[i])
        {
            for(j = i*i; j <= mx; j+=i)
                a[j] = 0;
        }
    }
}
int main()
{
    IOS
    sieve();

    ll t,n,q,i,l,r;
    ll sum[mx];


    cin>>n>>q;
    int b[n+1];

    for(i = 1; i <= n; i++)
    {
        cin>>b[i];
    }
    for(i = 1; i <= n; i++)
    {
        if(i==1)
        {
            if(a[b[i]])
                sum[i] = 1;
            else
                sum[i] = 0;
        }
        else
        {
            if(a[b[i]])
                sum[i] = sum[i-1]+1;
            else
                sum[i] = sum[i-1];
        }
    }
    while(q--)
    {
        cin>>l>>r;
        if(l==1)
          cout<<sum[r]<<endl;
        else
          cout<<sum[r]-sum[l-1]<<endl;
    }



    return 0;
}

