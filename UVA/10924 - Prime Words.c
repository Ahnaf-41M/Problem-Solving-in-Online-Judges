#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,sum = 0,count = 0;
    char s[22];

    while(scanf("%s",s) != EOF)
    {
        sum = 0;
        count = 0;
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i]>= 'A' && s[i] <='Z')
            {
                sum = sum + (s[i] - 'A') + 27;

            }
            else
            {
                sum = sum + (s[i] - 'a') + 1;
            }
        }


        for(i = 2; i <= sqrt(sum); i++)
        {
            if(sum%i == 0)
            {
                count=1;
                break;
            }
        }
        if(count == 0)
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
    }
}
