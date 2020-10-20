
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 10000005
ll a[Max];
vector<ll> v;
ll b[Max];

void seive()
{
    ll i,j;
    a[0]=0,a[1]=0,a[2]=1;

    for(i = 3; i <= Max; i+=2)
        a[i]=1;
    for(i = 3; i < sqrt(Max); i++)
    {
        if(a[i]==1)
        {
            for(j = 2; j*i <= Max; j++)
            {
                a[i*j]=0;
            }
        }
    }
    //v.push_back(2);
    for(i = 1; i <= Max; i++)
        {
             if(a[i-1]==1)
               b[i] = b[i-1]+1;
             else
               b[i] = b[i-1];

        }
}

int main()
{
    ll i,j,n,t,cnt=0;
    seive();

    cin>>t;
    while(t--)
    {
         cin>>n;

         cout<<b[n]<<endl;
         cnt=0;
    }

    return 0;
}
