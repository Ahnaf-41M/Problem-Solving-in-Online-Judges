#include<stdio.h>
int main()
{
    int c,f, i, t;
    double result, r2 = 0;

    scanf("%d",&t);

    for(i = 0; i < t; i++)
    {
        scanf("%d %d",&c, &f);

        result =5*(f-32)/9 + c;

        printf("%.2lf\n",result);
        result = 0;
    }

    return 0;
}
