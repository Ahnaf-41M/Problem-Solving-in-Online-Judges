#include<stdio.h>
int main()
{
    int t,a,b,i=0,sum = 0,k=0;

    scanf("%d",&t);

    while(t--)
    {
        k++;
        scanf("%d %d",&a, &b);

        for(i = a; i <= b; i++)
        {
            if(i % 2 != 0)
            {
                sum = sum + i;
            }
        }

        printf("Case %d: %d\n",k, sum);

        sum = 0;
    }
    return 0;
}
