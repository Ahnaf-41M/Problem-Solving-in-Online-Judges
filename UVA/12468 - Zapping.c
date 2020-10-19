#include<stdio.h>
int main()
{
    int a,b,t;

    while(scanf("%d %d",&a, &b)==2 && a>=0 && b>=0)
    {
        if(a-b <= 49 && a>b)
        {
            printf("%d\n",a-b);
        }
        else if(b-a <= 49 &&  b>a)
        {
            printf("%d\n",b-a);
        }

        else
        {
            if(b>a)
            {
                printf("%d\n",100-(b-a));
            }
            else
            {
                printf("%d\n",100-(a-b));
            }
        }
    }
    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int a,b,i,c;
 while(scanf("%d%d",&a,&b)==2&& a>=0&&b>=0)
 {
     c=abs(a-b);
     if(c>=50)
     c=100-c;

   printf("%d",c);
 }
 return 0;
} */


