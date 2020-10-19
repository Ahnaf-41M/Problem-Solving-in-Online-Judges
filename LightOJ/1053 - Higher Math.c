#include<stdio.h>
#include<math.h>

int main()
{
    int T,i,a,b,c;

    scanf("%d",&T);

    if(T<=200){

    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&a,&b,&c);

        if(sqrt(a*a+b*b)==c)
        {
            printf("Case %d: yes\n",i);

        }
        else if(sqrt(a*a+c*c)==b)
        {
            printf("Case %d: yes\n",i);

        }
        else if(sqrt(b*b+c*c)==a)
        {
           printf("Case %d: yes\n",i);

        }
        else{
            printf("Case %d: no\n",i);
        }
        }
    }
            return 0;

}
