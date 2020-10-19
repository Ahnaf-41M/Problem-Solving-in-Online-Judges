#include<bits/stdc++.h>
using namespace std;

#define mx 5000005
#define ll long long
int phi[mx];
unsigned ll sum[mx];

void totient()
{
    int i,j;

    for(i = 2; i <= mx; i++)
        phi[i]=i;

    for(i = 2; i <= mx; i++)
    {
        if(phi[i]==i)
        {
            for(j = i; j<=mx; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
void cumsum()
{

    int i;
    sum[1]=0;

    for( i=2; i<=mx; i++)
    {
        sum[i] = phi[i];
        sum[i]*=phi[i];
        sum[i]+=sum[i-1];
    }
}
int main()
{
    totient();
    cumsum();
    int n,i,a,b,j;
    scanf("%d",&n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",i,sum[b]-sum[a-1]);
    }
}
