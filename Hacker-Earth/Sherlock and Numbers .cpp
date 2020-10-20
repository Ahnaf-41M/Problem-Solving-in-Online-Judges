#include<bits/stdc++.h>
using namespace std;

#define ll long long

int Numbers(ll a[100000],ll p,ll k,ll n)
{
    if(p+k>n) return -1;

    for(ll i = 1; i <= k; i++)
    {
        if(p < a[i]) return p;
        p++;
    }
    return p;
}

int main()
{
    ll n,k,p,i,t;
    ll a[100000];

    cin>>t;

    while(t--)
    {
        cin>>n>>k>>p;

        for(i = 1;i <= k; i++)cin>>a[i];
        cout<<Numbers(a,p,k,n)<<endl;
    }
}
