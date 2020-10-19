#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,mn=0,sum=0,t,j,k;
    ll a[9];
    bool flg[9];
    for(i = 1; i <= 8; i++)
    {
        cin>>a[i];
        flg[i] = true;
    }
    cin>>t;
    while(t--)
    {
        cin>>j>>k;
        if(a[j]>a[k])
        {
            flg[j]=true;
            flg[k]=false;
        }
        else
        {
            flg[k]=true;
            flg[j]=false;
        }
    }
    for(i = 1; i <= 8; i++)
    {
        if(flg[i])
            sum+=a[i];
    }
    cout<<sum<<endl;

}
