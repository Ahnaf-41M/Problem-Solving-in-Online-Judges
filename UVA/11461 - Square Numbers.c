#include<stdio.h>
#include<math.h>
int main()
{
    long long int a,b,i, count = 0;
    double sq_root;

    while(1)
    {
        count = 0;
        scanf("%lld %lld",&a, &b);

        for(i = a; i <= b; i++)
        {
            sq_root = sqrt(i);

            if(a == 0 && b == 0)
               break;

            else if(ceil(sq_root) == floor(sq_root))
            {
                count++;
            }
        }
        if(a == 0 && b == 0)
            break;
        else
        printf("%lld\n",count);
    }

    return 0;
}
