#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c;

    while(scanf("%d",&n)!=EOF)
    {
        c=0;
        if((n%400==0)||(n%4==0 && n%100!=0))
        {
            printf("This is leap year.\n");
            c=1;
            if(n%55==0)
            {
                printf("This is buluculu festival year.\n");
                c=1;
            }
        }
        if(n%15==0)
        {
            printf("This is huluculu festival year.\n");
            c=1;
        }

        if(c==0)
            printf("This is an ordinary year.\n");
        printf("\n");


    }
}
