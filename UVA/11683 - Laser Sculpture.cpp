#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,c,i,cnt=0,a;

    while(scanf("%d%d",&a,&c)&&a!=0)
    {
        int b[c];
        cnt=0;
        for(i = 0; i < c; i++)
        {
            scanf("%d",&b[i]);
            if(i==0)
                cnt+=(a-b[i]);
            else
            {
                if(b[i-1]-b[i]>0)
                    cnt+=(b[i-1]-b[i]);
            }
        }
        printf("%d\n",cnt);

    }
}
