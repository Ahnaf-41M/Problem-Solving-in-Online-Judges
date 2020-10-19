#include<stdio.h>
int main()
{
    int t, i, a[50], p, j, m, n;

    scanf("%d",&t);

    for(i = 0;i < t; i++)
    {
        scanf("%d",&p);

        for(j = 0;j < p; j++)
        {
            scanf("%d",&a[j]);
            m = a[0];
            n = a[p-1];
        }
        printf("Case %d: %d\n",i+1,n-m);
        n = 0;
        m = 0;
    }
    return 0;

}
