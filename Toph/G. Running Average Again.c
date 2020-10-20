#include<stdio.h>
int main()
{
    int N,i;
    float a1,a,s=0;

    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
        scanf("%f",&a);

        s=s+a;

        printf("%f\n",(float)(s/i));
    }
    return 0;
}
