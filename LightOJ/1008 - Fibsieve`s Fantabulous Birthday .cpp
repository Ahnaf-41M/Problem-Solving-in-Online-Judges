#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,row,col,n,p,q;
    double x;

    scanf("%d",&t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        x = sqrt(n);
        if(ceil(x)*floor(x)==n)
        {
            if(n & 1)
                printf("Case %d: 1 %lf\n",i,x);

            else
                printf("Case %d: %lf 1\n",i,x);
        }
        else
        {
             row = ceil(x);
             q = floor(x);
             col = n%q;
             printf("Case %d: %d %d\n",i,col,row);
        }
    }
}
