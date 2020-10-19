#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,c,i,j,mx=0,amp=0,x,tc=1;
    bool flag = true;

    while(scanf("%d%d%d",&n,&m,&c) && n!=0 &&m!=0&&c!=0)
    {

        flag = true;
        amp=0, mx=0;
        bool check[n+1];
        int a[n+1];
        memset(check,false,sizeof check);

        for(i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d",&x);
            if(!check[x])
            {
                check[x] = true;
                amp+=a[x];
                if(amp>c)
                    flag = false;
                mx = max(mx,amp);
            }
            else
            {
                check[x] = false;
                amp-=a[x];
            }

        }
        if(flag)
        {
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",tc,mx);
        }
        else
            printf("Sequence %d\nFuse was blown.\n\n",tc);
        tc++;
    }
}
