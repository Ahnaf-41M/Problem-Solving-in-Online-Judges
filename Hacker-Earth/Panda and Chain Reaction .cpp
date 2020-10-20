#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll i,t,x,n;
    ll mx = pow(10,6)+3;
    ll a[mx+4];

    a[0]=1;
    for(i = 1; i <=mx; i++)
    {
        a[i] = (a[i-1]%mx*i%mx)%mx;
     }

    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        if(n>=mx)
            cout<<"0\n";
        else
            cout<<((a[n]%mx)*(x%mx))%mx<<endl;
    }
}
