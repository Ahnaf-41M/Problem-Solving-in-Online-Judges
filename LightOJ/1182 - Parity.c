#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,sum=0,t;
    long long int n;
    int a[1000];

    scanf("%d",&t);

    for(i = 0;i < t;i++)
    {
        scanf("%lld",&n);

        for(j = 0; n > 0;j++)
        {
            a[j]=n%2;
            n=n/2;

            if(a[j] == 1)
            {
                sum = sum +1;
            }
        }
        if(sum % 2 == 0)
        {
            printf("Case %d: even\n",i+1);
        }
        else
        {
            printf("Case %d: odd\n",i+1);
        }
        sum=0;
    }
    return 0;
}
