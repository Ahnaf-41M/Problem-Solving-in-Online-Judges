#include<stdio.h>
#include<math.h>

int main()
{
    int t,k1,i,j;
    double tax,k;

    scanf("%d",&t);

    for(i = 1; i <= t; i++)
    {

        tax = 0.0;

        scanf("%d",&k1);
        k = k1*1.0;

        if(k<=180000)
        {
            tax = 0.0;
        }
        else
        {
            while(k>0)
            {
                k = k-180000;

                if(k<=300000)
                {
                    tax =  k*.1*1.0;
                    k = k- 300000;
                }
                else if(k>300000 && k<=700000)
                {
                    k = k-300000;
                    tax = 30000+ k*.15*1.0;
                    k = k-400000;
                }
                else if(k>700000 && k<=1000000)
                {
                    k = k-700000;
                    tax =90000+k*.2*1.0;
                    k = k-300000;
                }
                else
                {
                    k = k - 1000000;
                    tax = .25*k+150000;
                    break;
                }

            }
        }
        tax = ceil(tax);
        if(tax>2000)
        {
            printf("Case %d: %.0lf\n",i,tax);
        }
        else if(tax>0 && tax<=2000)
            printf("Case %d: 2000\n",i);
        else
            printf("Case %d: 0\n",i);
    }
    return 0;
}
