#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,b,h,w,p,mx,ans;
    while(scanf("%d%d%d%d",&n,&b,&h,&w)==4)
    {
         mx = 0;
         ans = b+1;
        for(int k = 0; k < h; k++)
        {
            int a;
            mx = 0;
            scanf("%d",&p);
            for(int i = 0; i < w; i++)
            {
                scanf("%d",&a);
                mx = max(a,mx);
            }
            if(mx>=n){
               ans = min(ans,n*p);
            }

        }
        if(ans==b+1)
            printf("stay home\n");
        else
          printf("%d\n",ans);

    }
}
