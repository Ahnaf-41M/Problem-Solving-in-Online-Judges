#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,l,k,c,l2;
    char s[1000],s1[1000],s3[1000];
    while(gets(s))
    {
        if(strcmp(s,"DONE")==0)
            break;

        l = strlen(s);
        c = 1;
        j=0;

        for(i = 0;i<l;i++)
        {

            if(s[i]>='a' && s[i]<='z' || s[i]<='Z'&&s[i]>='A')
            {
                s1[j] = s[i];
                j++;
            }
        }
        s1[i]='\0';
        strcpy(s3,s1);
        if(strcmp(s1,s3)==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
