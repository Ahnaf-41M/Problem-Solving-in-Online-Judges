#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int l,n1,n2,i,j,c1 = 0,c2 = 0,sq,sq2;
    char s[20],s2[20];

    while(scanf("%s",&s) != EOF)
    {
        l = strlen(s);
        n1 = 0;
        n2 = 0;
        c1=0;
        c2=0;
        sq=0,sq2=0;

        for(i = 0,j = l-1;j>=0,i < l; j--,i++)
        {
            n1 = (s[i] - '0') * pow(10,j)+n1;
        }
        sq = sqrt(n1);

        for(i = 1; i <= sq; i++)
        {
            if(n1%i == 0)
            {
                c1++;
            }
        }

        for(i = 0,j = l-1; i < l,j>=0;i++,j--)
        {
            s2[i] = s[j];
        }

        for(i = 0,j = l-1;j>=0,i < l; j--,i++)
        {
            n2 = (s2[i] - '0') * pow(10,j)+n2;
        }

        sq2 = sqrt(n2);
        for(i = 1; i <= sq2; i++)
        {
            if(n2%i == 0)
            {
                c2++;
            }
        }
        printf("%d %d %d %d\n",n1,n2,c2,c1);
        if(c1+1==2 && c2+1==2)
            printf("%d is emirp.\n",n1);
        else if(c1+1<=2)
            printf("%d is prime.\n",n1);
        else
            printf("%d is not prime.\n",n1);

    }

}
