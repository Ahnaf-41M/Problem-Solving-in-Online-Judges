#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000];
    int i,cnt = 0;

    while(gets(s))
    {
        cnt = 0;

        for(i = 0; i < strlen(s); i++)
        {
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z') )
            {
                cnt = cnt;
            }
            else
            {
            if((s[i-1]>='a' && s[i-1]<='z')||(s[i-1]>='A' && s[i-1]<='Z') )
            {
                cnt++;
            }
            else
                cnt = cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
