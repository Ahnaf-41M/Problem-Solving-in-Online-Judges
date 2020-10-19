#include<stdio.h>
int main()
{
    int i,rem,a[11],count = 0,n,j,p;

    scanf("%d",&n);

    for(i = n+1; i <= 9000; i++)
    {

        rem = 0,p=i,count = 0;

        for(j = 0; j < 11; j++)
        {
            a[j] = 0;
        }
        while(p>0)
        {
            rem = p%10;
            a[rem] = a[rem] + 1;
            p = p/10;
        }
        for(j = 0; j < 10; j++)
        {
            if(a[j]>1)
                count++;
        }
        if(count==0){
            printf("%d\n",i);
            break;}

            count=0;
    }
    return 0;
}
