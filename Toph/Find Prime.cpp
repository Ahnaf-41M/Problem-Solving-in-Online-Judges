#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 10005
int a[Max];
vector<int> v;

void seive()
{
    int i,j;
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
    v.push_back(2);
    for(i = 3; i <= Max; i+=2)
        if(a[i]==1)
            v.push_back(i);

}

int main()
{
    int i,t,n;
    seive();

    cin>>t;

    while(t--)
    {
        cin>>n;
        for(i = n-1; i>=2; i--)
            if(a[i]==1)
            {
                cout<<i<<" ";
                break;
            }

        for(i = n+1; ;i++)
        {
             if(a[i]==1)
             {
                  cout<<i<<endl;
                  break;
             }
        }
    }

    return 0;
}

