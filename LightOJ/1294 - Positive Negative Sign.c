#include<stdio.h>
int main()
{
    int T,i;
    long long int n,m;

    scanf("%d",&T);

    if(T<=10000)
    {
        for(i=1;i<=T;i++)
        {
            scanf("%d %d",&n,&m);
            if(n>=2 && m>=1 && n%2*m==0)
            {
                printf("Case %d: %d\n",i,(m*n/2));
            }
        }
    }
    return 0;
}
