#include<stdio.h>
int main()
{
    int N,i,s=-1;

    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
        if(N%i==0)
        {
            s=s+1;
        }
    }
    printf("%d\n",s);


    return 0;
}
