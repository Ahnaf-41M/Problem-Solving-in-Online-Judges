#include<stdio.h>
int main()
{
    long long int a;
    int t,b,i;

    scanf("%d",&t);

    for(i = 0; i < t;i++)
    {
        scanf("%lld %d",&a,&b);
        if(b< 0)
        {
            b=(-1) * b;
        }

        if(a % b == 0)
        {
            printf("Case %d: divisible\n",i+1);
        }
        else
        {
            printf("Case %d: not divisible\n",i+1);
        }
    }
    return 0;
}
