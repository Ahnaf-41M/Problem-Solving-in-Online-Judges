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

int find_div(int n)
{
    int i,j;
    int cnt=0;

    if(n==1)
     return 1;
    for(j = 2; j <= sqrt(n); j++)
    {
        if(n%j==0)
        {
            if(n/j==j)
                cnt++;
            else
                cnt+=2;
        }
    }
    return cnt+2;
}
int main()
{
    IOS

    int t,a,b,com;

    cin>>t;

    while(t--)
    {
        cin>>a>>b;
        com = gcd(a,b);

        cout<<find_div(com)<<endl;
    }


    return 0;
}


