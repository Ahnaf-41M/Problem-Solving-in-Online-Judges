#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll sum,fact[22],ans;
    ll t,i,j,l,cnt;

    fact[1]=1;
    for(i = 2; i <= 20; i++)
    {
        fact[i] = i*fact[i-1];
        //cout<<fact[i]<<endl;
    }

    cin>>t;
    string s;
    int a[28];
    for(i = 1; i <= t; i++)
    {
        memset(a,0,sizeof(a));

        cin>>s;
        l = s.size();
        ans = fact[l];
        for(j = 0; j < l; j++)
        {
            a[s[j]-64]++;
        }
        for(j = 0; j < 27; j++)
        {
            if(a[j])
            {
                ans/=fact[a[j]];
            }
        }
        printf("Data set %lld: %lld\n",i,ans);

    }

    return 0;


}
