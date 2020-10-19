#include<stdio.h>
int main()
{
    long long int n, sum = 0;

    while(1)
    {
        scanf("%lld",&n);

        if(n<0){
            break;}
        else{
            sum = (n*(n-1)/2)+n+1;
        printf("%lld\n",sum);}
        sum = 0;
    }

    return 0;
}
