#include<stdio.h>
int main()
{
    int n,T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        if(n<=10)
        {
            printf("0 %d\n",n);
        }
        else
        {
            printf("%d 10\n",(n-10));
        }
    }
    return 0;
}
