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
map<int,int> mp;

void find_num()
{
    int sum=0;
    int i,j;
    for(i = 1; i <= 5000; i++)
    {
        for(j = 1; j <= sqrt(i); j++)
        {
            if(i%j==0)
            {
                if(i/j==j)
                    sum+=j;
                else
                {
                    sum+=j;
                    sum+=i/j;
                }
            }
        }
        if(sum<=1000)
            mp[sum]=i;
        sum=0;
    }
}
int main()
{
    IOS
    find_num();
    int i,j,sum=0;
    int n;
    int cs=1;
    while(cin>>n)
    {
        if(n==0)
            break;
        if(mp[n]==0)
            pf("Case %d: -1\n",cs);
        else
            pf("Case %d: %d\n",cs,mp[n]);
        cs++;
    }


    return 0;
}

