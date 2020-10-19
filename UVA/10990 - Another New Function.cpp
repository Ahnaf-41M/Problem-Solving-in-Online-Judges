#include<bits/stdc++.h>
#define sc scanf
#define pf printf
using namespace std;

#define ll long long
#define MAX 3000005
ll phi[MAX];
ll depth_phi[MAX];
ll ans[MAX];
void find_phi()
{
    ll i,j;
    for(i=2; i<=MAX; i++)
        phi[i]=i;
    for(i=2; i<=MAX; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=MAX; j+=i)
                phi[j]-=phi[j]/i;//Inclusion_Exclusion Law use
        }
    }
}
void depth_of_phi()
{
    depth_phi[2]=1;
    ll temp,cnt=0;

    for(ll i = 3; i <= MAX; i++)
    {
        temp = i;
        while(phi[temp]!=1)
        {
            cnt++;
            temp = phi[temp];
        }
        cnt++;
        depth_phi[i] = cnt;
        cnt=0;

    }
}
void cumulative_sum_of_depth()
{
     ans[2]=depth_phi[2];

     for(ll i = 3; i <= MAX; i++)
     {
          ans[i] = (ans[i-1]+depth_phi[i]);
     }
}
int main()
{
    find_phi();
    depth_of_phi();
    cumulative_sum_of_depth();
    ll n,t,m,cnt=0,i,temp;

    sc("%lld",&t);

    while(t--)
    {
        sc("%lld%lld",&n,&m);

        pf("%lld\n",ans[m]-ans[n-1]);
        cnt=0;
    }
}
