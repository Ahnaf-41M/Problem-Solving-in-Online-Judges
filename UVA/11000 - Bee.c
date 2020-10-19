#include<stdio.h>


int male(int n)
{
    int i,fib[n];
    int c=0;


    fib[0]=0;
    fib[1]=1;

    for(i = 2; i <= n; i++)
    {
           fib[i] = fib[i-1]+fib[i-2];
           c+=fib[i];

    }
    return c;
}
int total(int p)
{
     int i,f[p];


    f[0]=0;
    f[1]=1;
    int count = 0;

    for(i = 2; i <= p; i++)
    {

            f[i] = f[i-1]+f[i-2];
            count+=f[i];
    }

    return count;
}


int main()
{
    int n,res = 0;

    while(scanf("%d",&n)!= EOF && n>=0)
    {
        if(n==0)
            printf("0 1\n");
        else
        printf("%d %u\n",male(n)+1,total(n+1)+1);
    }
    return 0;
}
