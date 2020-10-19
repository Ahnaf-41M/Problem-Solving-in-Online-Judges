#include<bits/stdc++.h>
using namespace std;
//LPS(a) = LCS(a, reverse(a))

int LPS(string x,string y)
{
    int n = x.size();
    int m = y.size();
    int i,j;
    int dp[n+1][m+1];

    for(i = 0; i <= n; i++)
      dp[i][0] = 0;
    for(j = 0; j <= m; j++)
      dp[0][j] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(x[i-1] == y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }         
        }
    }
    return dp[n][m];
}
int main()
{
    int t,i;
    
    scanf("%d",&t);

    for(i = 1; i <= t; i++)
    {
        string x,y;

       cin>>x;
       y = x;
       reverse(y.begin(),y.end());

       printf("Case %d: %d\n",i,x.size()-LPS(x,y));
    }
}