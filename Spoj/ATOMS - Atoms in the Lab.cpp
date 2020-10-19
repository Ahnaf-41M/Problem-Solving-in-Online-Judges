#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll unsigned long long

int main()
{
    IOS
    ll t,n,m,k,T=0,atoms=1,i;
    cin>>t;

    while(t--)
    {
        cin>>n>>k>>m;

        if(k<=(m/n))
        {
            n*=k;
            T++;
            while(k<=(m/n))
            {
                n*=k;
                T++;
            }
        }
        cout<<T<<endl;
        T=0;
    }

}
