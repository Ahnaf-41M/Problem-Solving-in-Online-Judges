#include<bits/stdc++.h>
using namespace std;

#define Max 10000000
int a[Max+5];
long long f[Max+5];

vector<int> v;
void sieve()
{
    int i,j;
    a[0]=0,a[1]=0,a[2]=2;

    for(i = 3; i <= Max; i+=2)
        a[i]=i;
    for(i = 2; i <= sqrt(Max); i++)
    {
        if(a[i]==i)
        {
            for(j = i; j <= Max; j+=i)
            {
                if(a[j]==0 || a[j]==j) /*Cause 6 can be multiplied by 2 and 3,but the answer is 2..*/
                    a[j]=i;
            }
        }
    }
}
void pre_calculate()
{
    f[2] = 2;

    for(int i = 3; i <= Max; i++)
    {
        f[i] = f[i-1] + a[i];
    }
}
int main()
{
    sieve();
    pre_calculate();
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }

}
