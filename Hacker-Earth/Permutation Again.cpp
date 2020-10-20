#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base:: sync_with_stdio(false),cin.tie(0),cout.tie(0);


int main()
{
    fast;
    ll t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        if(n==1)
            cout<<1<<endl;
        else
        {
            //n-=1;
            cout<<(n*n)/2-1<<endl;
        }
    }
}
