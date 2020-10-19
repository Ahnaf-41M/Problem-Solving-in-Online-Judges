#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,c1 = 0, count = 0,j;
    scanf("%d",&t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        int a[n];
        for(j = 0; j < n; j++)
        {
            scanf("%d",&a[j]);
            count+=a[j];
        }

        for(j = 0; j < n ;j++)
        {
            if(a[j]> (double)(count*1.0/n*1.0))
            {
                c1++;
            }
        }

        printf("%.3lf%%\n",(double)(c1*1.0/n*1.0)*100);

        c1=0;
        count = 0;
    }

    return 0;
}
