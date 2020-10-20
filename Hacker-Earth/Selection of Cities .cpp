#include<iostream>
using namespace std;
#define ll long long
#define mod 1000000007
ll powr(ll n)
{
    ll p=1;
    ll base=2;
    while(n>0)
    {
        if(n&1)
            p=(p*base)%mod;
        base=(base*base)%mod;
        n/=2;
    }
    return p;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<(powr(n)%mod-1+mod)%mod<<endl;
    }

    return 0;
}
