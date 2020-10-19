#include<stdio.h>
int main()
{
    int n;

    while(scanf("%d",&n) == 1)
    {
        if(n == 0)
            break;
        else
        printf("%d",n);
    }
    return 0;
}
