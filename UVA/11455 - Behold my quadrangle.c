#include<stdio.h>
int main()
{
    int t, a, b, c, d, i;

    scanf("%d",&t);

    for(i = 0; i < t; i++)
    {
        scanf("%d %d %d %d",&a, &b, &c, &d);

        if(a==b && b==c && c==d && d==a)
        {
            printf("square\n");
        }
        else if(a==b && c==d || a==c && d==b || a==d && c==b)
        {
            printf("rectangle\n");
        }
        else if(a+b+c < d || a+c+d < b || a+b+d < c || b+c+d < a)
        {
            printf("banana\n");
        }
        else
            printf("quadrangle\n");
    }

    return 0;
}
