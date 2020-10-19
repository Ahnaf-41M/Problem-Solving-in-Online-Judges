#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30001];
int a[] = {1,5,10,25,50};
void Count()
{
    ll i,j;
    dp[0]=1;
    for(i = 0; i < 5; i++)
    {
        for(j = a[i]; j <= 30000; j++)
        {
            dp[j]+=dp[j-a[i]];

        }
    }

    //return dp[n][make];
}
int main()
{

    int make,numOFways;
    Count();

    while(scanf("%d",&make)!=EOF)
    {
        if(dp[make]==1)
            printf("There is only %lld way to produce %d cents change.\n",dp[make],make);
        else
            printf("There are %lld ways to produce %d cents change.\n",dp[make],make);

    }
}

