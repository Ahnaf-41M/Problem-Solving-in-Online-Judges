#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,i,j,d,k,y,z;
    char ch;
    cin>>t;

    for(i = 1; i <= t; i++)
    {
        cin>>n>>m;
        int a[n];
        for(j = 0; j < n; j++)
            cin>>a[j];
        while(m--)
        {
            cin>>ch;
            if(ch=='S')
            {
                cin>>d;
                for(k = 0; k < n; k++)
                {
                    a[k]+=d;
                }
            }
            else if(ch=='M')
            {
                cin>>d;
                for(k = 0; k < n; k++)
                    a[k]*=d;
            }
            else if(ch=='D')
            {
                cin>>d;
                for(k = 0; k < n; k++)
                    a[k]/=d;
            }
            else if(ch=='R')
                sort(a,a+n,greater<int>());
            else
            {
                cin>>y>>z;
                swap(a[y],a[z]);
            }
        }
        printf("Case %d:\n",i);
        for(j = 0; j < n; j++)
            cout<<a[j]<<" ";
        cout<<endl;
    }
}
