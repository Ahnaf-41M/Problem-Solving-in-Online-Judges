#include<stdio.h>

int main()
{
    int n,k,sum,p;

    while(scanf("%d %d",&n,&k) != EOF)
    {
        sum = 0;
        p = n;
        while(n>0)
        {
            sum = sum+n/k;
            n = n/k+n%k;
            if(n>1 && n<k)
            {
             sum+=1;
             break;
            }

        }
        printf("%d\n",sum+p-1);
    }
    return 0;
}

