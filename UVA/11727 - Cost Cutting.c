#include<stdio.h>
int main()
{
    int t, i, x, y, z;

    scanf("%d",&t);

    for(i = 0; i < t; i++)
    {
        scanf("%d %d %d",&x, &y, &z);

        if(x>y && x<z || x>z && x<y)
            printf("Case %d: %d\n",i+1,x);
        else if(y>x && y<z || y>z && y<x)
            printf("Case %d: %d\n",i+1,y);
        else
            printf("Case %d: %d\n",i+1,z);

    }
    return 0;
}
