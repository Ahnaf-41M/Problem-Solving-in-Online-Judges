#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 1000005
ll a[Max];

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
}

int main()
{
    ll i,j,n,t,k,x;
    seive();
    cin>>t;

    while(t--)
    {
        ll sum=0,c=0;
        cin>>n>>k;
        while(n--)
        {
            cin>>x;
            if(a[x]==1)
            {
                c++;
                if(k==c)
                {
                    sum+=x;
                    c-=k;
                }
            }
        }
        cout<<sum<<endl;
    }


    return 0;
}
