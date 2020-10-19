#include<stdio.h>
int main()
{
    long long int a,b,c,d,L,f,i,count = 0;

    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&L) != EOF)
    {
        if(a==0 && b==0 && c==0 && d==0 && L==0)
            break;
        else
        {
            for(i = 0; i <= L; i++)
            {
                f = a*i*i + b*i + c;

                if(f%d == 0)
                {
                    count++;
                }
            }
        }
        printf("%lld\n",count);
        count = 0;
    }
    return 0;
}
