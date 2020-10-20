#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 100000000
bool a[Max+5];
vector<ll> v;
ll b[Max+5];
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

    int k=1;
    b[k] = 2;
    k++;
    for(i = 3; i <= Max; i+=2)
    {
        if(a[i])
        {
            b[k] = b[k-1]+i;
            k++;
        }
    }
}

int main()
{
    int i,j,n;
    seive();

    int t,x,y;
    cin>>t;

    while(t--)
    {
        cin>>x>>y;
        if(x>y)
          swap(x,y);
        cout<<b[y]-b[x-1]<<endl;
    }

    return 0;
}

