#include<stdio.h>
int main()
{
    int n, sum = 0, rem = 0, p =0, count = 0;


    while(scanf("%d",&n) != EOF)
    {
        if(n==0)
            break;
       while(n>0)
       {
           rem = n/3;
           sum = rem+sum;

           if(n==1)
           {
               break;
           }
           else if(n==2)
           {
               sum+=1;
               break;
           }
             n = n/3 + n%3;

       }
       printf("%d\n",sum);

       sum = 0;
    }

    return 0;
}
