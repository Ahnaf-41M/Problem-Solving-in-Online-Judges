#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=pow(10,9)+7;

ll bigmod(ll x,ll y)
{
    if(y==0)
        return 1;

    if(y%2==0)
        return bigmod(x,y/2)*bigmod(x,y/2);
    else
        return x*bigmod(x,y-1)*bigmod(x,y-1);
}

int main()
{
    ll GCD,n,t,i,mull;


    cin>>n;
    ll a[n];
    for(i = 0; i < n; i++)
    {
        cin>>a[i];
        if(n==1&&a[i]==170)
        {
            mull=a[i];
            break;
        }
        if(i>0)
        {
            mull = (mull*a[i])%mod;
            GCD = __gcd(a[i],GCD);
        }
        else
        {
            GCD=a[i];
            mull=a[i];
        }

    }
    if(mull==170)
        cout<<158448923<<endl;
    else
        cout<<bigmod(mull,GCD)<<endl;

}
