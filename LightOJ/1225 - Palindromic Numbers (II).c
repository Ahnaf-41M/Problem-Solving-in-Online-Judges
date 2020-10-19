#include<stdio.h>
int main()
{
    int t,sum=0,n,temp,i,rem;

    scanf("%d",&t);

    for(i = 0; i < t; i++)
    {
        scanf("%d",&n);

        temp = n;
        sum=0;

        while(temp != 0)
        {
            rem = temp % 10;
            sum = sum * 10+rem;
            temp = temp /10;
        }
        if(n == sum)
        {
            printf("Case %d: Yes\n",i+1);
        }
        else
            printf("Case %d: No\n",i+1);
    }
    return 0;
}
