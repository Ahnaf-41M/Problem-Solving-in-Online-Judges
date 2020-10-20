#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,q,i,m,index,sum=0;
    cin>>n>>q;
    ll ar1[n],a1[n];
    for(i=0; i<n; i++){
        scanf("%lld",&ar1[i]);
        sum+=ar1[i];
        a1[i]=sum;
    for(i=1;i<=q;i++)
    {
        cin>>m;
        index=lower_bound(a1,a1+n,m)-a1;
        printf("%lld\n",index+1);
    }

}
