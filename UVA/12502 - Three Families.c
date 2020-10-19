#include<stdio.h>
int main()
{
    int n,i, x, y, z;
    scanf("%d",&n);

    for(i = 1; i <=n ;i++)
    {
        scanf("%d %d %d",&x,&y,&z);

        if(z%(x+y) == 0)
        {
            printf("%d\n",z-(((x+y)/3)*10));
        }
        else
        {
            printf("%d\n",z);
        }
    }
    return 0;
}

