#include<stdio.h>
int main()
{
    int a,b,s,m;

    scanf("%d%d",&a,&b);
    s=a/b;
    m=(a%b);

    printf("%d %d %d",s,m,b);

    return 0;
}
