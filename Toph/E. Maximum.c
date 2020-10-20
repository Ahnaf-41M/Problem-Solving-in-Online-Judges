#include<stdio.h>
int main()
{
    int N,i,a,s=0;

    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
        scanf("%d",&a);
        if(a>s)
        {
         s=a;
        }
    }
    printf("%d",s);

    return 0;
}
