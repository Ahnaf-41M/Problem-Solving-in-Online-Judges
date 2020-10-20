#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll res,d,x,a,b,i,t,m,s=0,j=0;

    cin>>t;

    while(t--)
    {
        cin>>d>>a>>m>>b>>x;
        j=0,i=0,s=0;
        res = d+x-(a*m);
        res=(res/2)+res%2;
        ll r1= res/a;
        ll r2 = (res-1)/b;

        cout<<m+r1+r2<<endl;
    }
    return 0;

}
