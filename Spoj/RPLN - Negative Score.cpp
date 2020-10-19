#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
int k = log2(MAX);
vector<vector<int> > dp(MAX);
void init()
{
    for(int i = 0; i < MAX; i++)
    {
        dp[i] = vector<int> (k);

        for(int j = 0; j < k; j++)
        {
            dp[i][j]=0;
        }
    }
}
void Make_Sparse(int a[],int n)
{
    int i,j;
    for(i = 0; i < n; i++)
        dp[i][0] = a[i];

    for(j = 1; (1 << j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
        {
            dp[i][j] = min(dp[i][j-1],dp[ i + (1 << (j-1))][j-1]);
        }
    }
}

int query(int l,int r)
{
    int k = (int)log2(r-l+1);

    return min(dp[l][k],dp[r - (1<<k) + 1][k]);
}
int main()
{
    init();
    int t,n,q,l,r;

    scanf("%d",&t);

    for(int i = 1; i <= t; i++)
    {
        scanf("%d%d",&n,&q);
        int a[n];

        for(int j = 0; j < n; j++)
            scanf("%d",&a[j]);

        Make_Sparse(a,n);

        printf("Scenario #%d:\n",i);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l-1,r-1));
        }
    }
}

