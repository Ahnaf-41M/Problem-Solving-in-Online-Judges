#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,q,i;

    cin>>n;
    ll a[n];

    for(i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        ll l=0,h=n,mid=(l+h)/2;
        while(l<h)
        {
            if(a[mid]<x)
            {
                l = mid+1;
            }
            else
            {
                h = mid;
            }
            mid = (l+h)/2;
        }
        cout<<mid<<endl;
    }
    return 0;
}
