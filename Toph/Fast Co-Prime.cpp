#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define ll long long

ll totient(ll n)
{
    ll res;

    if(n==1)return 1;

    res=n;

    if(n%2==0)
    {
        res-=res/2;

        while(n%2==0)
        {
            n/=2;
        }
    }

    for(int i = 3; i*i<=n; i+=2)
    {
        if(n%i==0)
        {
            res-=res/i;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1)return res-=res/n;

    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,t;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        ll ans = totient(n)*(k-1);
        cout<<ans<<endl;
    }

}
