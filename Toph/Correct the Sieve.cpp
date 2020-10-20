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
    ll i,j,n,t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    cin>>t;
    while(t--){
    cin>>n;
    if(a[n]==1)
        cout<<n<<" is a prime number.\n";
    else
        cout<<n<<" is not a prime number.\n";
    }

    return 0;
}

