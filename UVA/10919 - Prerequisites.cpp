#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,m,c,r,rr=0;

    while(scanf("%d",&k) && k!=0)
    {
        scanf("%d",&m);
        int a[k],cnt=0;
        bool flag = true;
        for(int i = 0; i < k; i++)
            cin>>a[i];
        rr=0;
        for(int t = 0; t < m; t++)
        {
            scanf("%d%d",&c,&r);
            int b[c];
            for(int i = 0; i < c; i++)
                scanf("%d",&b[i]);

            for(int i = 0; i < c; i++)
            {
                for(int j = 0; j < k; j++)
                {
                     if(b[i]==a[j])
                         cnt++;
                     if(cnt==r)
                         break;
                }
                if(cnt==r)
                    break;
            }
            if(cnt==r)
               rr++;
            cnt=0;
        }
        if(rr>=m)
            printf("yes\n");
        else
            printf("no\n");

    }
}
