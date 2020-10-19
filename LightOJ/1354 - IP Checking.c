#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,t,a[4],b[4],reminder;

    scanf("%d",&t);

    for(i = 0; i < t;i++)
    {
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);

        b[0] = binary(b[0]);
        b[1] = binary(b[1]);
        b[2] = binary(b[2]);
        b[3] = binary(b[3]);

        if(a[0]==b[0] && a[1]==b[1] && b[2]==a[2] && a[3]==b[3])
        {
            printf("Case %d: Yes\n",i+1);
        }
        else
        {
            printf("Case %d: No\n",i+1);
        }

    }
    return 0;
}
int binary(int bin)
{
    int reminder,h=0,sum=0;

    while(bin!=0)
    {
        reminder=bin%10;
        bin=bin/10;
        sum=sum+reminder*pow(2,h++);
    }
    return sum;
}
