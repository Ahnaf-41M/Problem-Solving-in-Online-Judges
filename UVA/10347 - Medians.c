#include<stdio.h>
#include<math.h>
int main()
{
    double C,B,A,s,area;

    while(scanf("%lf%lf%lf",&A,&B,&C)!=EOF)
    {
        s=0.0;


        s = (A*1.0+B*1.0+C*1.0)/2*1.0;

        area = (4*1.0/3*1.0)*sqrt(s*(s-A)*(s-B)*(s-C));

        if(area>0.0)
        printf("%.3lf\n",area);
        else
            printf("-1.000\n");
        area = 0.0;

    }
    return 0;
}
