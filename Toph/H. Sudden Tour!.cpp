#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Returns the maximum value that can be put in a knapsack of capacity W
ll knapSack(ll W, ll wt[], ll val[], ll n)
{
    ll i, j;
    vector<vector<ll> > K;
    K.assign(n+1,vector<ll>(W+1));

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i==0 || j==0)
                K[i][j] = 0;
            else if (wt[i-1] <= j)
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }

    return K[n][W];
}

int main()
{
    ll t,n,cap,W;
    cin>>t;
    for(int k = 1; k <= t; k++)
    {
        cin>>n>>W;
        ll val[n+1],wt[n+1];
        for(int i = 0; i < n; i++)
        {
            cin>>wt[i]>>val[i];
        }
        printf("Case %d: %lld\n",k, knapSack(W, wt, val, n));
    }
    return 0;
}
