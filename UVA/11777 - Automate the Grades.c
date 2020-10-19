#include<stdio.h>
int main()
{
    int i,t,t1,t2,f,at,ct1,ct2,ct3;
    double ct, sum = 0;

    scanf("%d",&t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&f,&at,&ct1,&ct2,&ct3);


        if(ct1>=ct3 && ct2>=ct3)
        {
            ct = (ct1+ct2)/2;
        }
        else if(ct2>=ct1 && ct3>=ct1)
        {
            ct = (ct2+ct3)/2;
        }
        else
        {
            ct = (ct1+ct3)/2;
        }
        sum = t1+t2+f+at+ct;


        if(sum>=90)
        {
            printf("Case %d: A\n",i);
        }
        else if(sum>=80 && sum<90)
        {
            printf("Case %d: B\n",i);
        }
        else if(sum>=70 && sum <80)
        {
            printf("Case %d: C\n",i);
        }
        else if(sum>=60 && sum<70)
        {
            printf("Case %d: D\n",i);
        }
        else
        {
            printf("Case %d: F\n",i);
        }
        sum = 0;

    }
    return 0;
}
