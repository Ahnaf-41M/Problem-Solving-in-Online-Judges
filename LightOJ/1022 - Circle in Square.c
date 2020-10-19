#include<stdio.h>
#include<math.h>
int main()

{
    int i,T;
    double r,pi=2*acos(0.0);

    scanf("%d",&T);

    if(T<=1000)
    {
        for(i=1;i<=T;i++)
        {
            scanf("%lf",&r);

            printf("Case %d: %.2lf\n",i,(4*r*r-(pi*r*r)));
        }

    }
    return 0;
}
