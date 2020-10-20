#include<stdio.h>
int main()
{
    int a[100],N,i;

    a[0]=0,a[1]=1;


    scanf("%d",&N);

    for(i=2;i<=N;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
            printf("%d",a[N]);

    printf("\n");
    return 0;

}

