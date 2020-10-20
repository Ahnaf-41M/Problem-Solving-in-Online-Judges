#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll i,j,n,t,m;
    ll mx = pow(10,9)+7;
    //cout<<mx;

    cin>>t;

    while(t--)
    {
        cin>>n;
        n = n%mx;
        cout<<(n*(2*n-1))%mx<<endl;

    }

}
