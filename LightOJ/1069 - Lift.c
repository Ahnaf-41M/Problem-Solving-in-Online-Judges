#include<stdio.h>
int main()
{
    int t,a,b,i;

    scanf("%d",&t);

    for(i=0; i<t; i++)
    {
        scanf("%d %d",&a,&b);
        if(b > a)
        {
            printf("Case %d: %d\n",i+1,b*4+19);
        }
        else
        {
            printf("Case %d: %d\n",i+1,(2*a-b)*4+19);
        }
    }
    return 0;
}
