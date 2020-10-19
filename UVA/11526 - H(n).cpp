#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H(ll n)
{
    ll res = 0;
    ll a = sqrt(n);
    for(int i = 1; i <= sqrt(n); i++ )
    {
        res = (res + n/i);
    }
    /*res-(the value we will get by iterating 
    the rest to n) = sqrt(n)*sqrt(n)*/
    res*=2;
    res-=(a*a);
    return res;
}
int main()
{
    ll t,n,i,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans = H(n);
        cout<<ans<<endl;
    }

}
