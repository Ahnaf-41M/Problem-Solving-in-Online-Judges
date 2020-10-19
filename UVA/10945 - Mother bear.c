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
        k=0;

        for(i = 0; s[i]!=NULL; i++)
        {

            if((s[i]>='a' && s[i]<='z') || (s[i]<='Z'&&s[i]>='A'))
            {
                if(s[i]>='A'&&s[i]<='Z')
                {
                    s1[j] = s[i]+32;
                    j++;
                }
                else
                {
                    s1[j] = s[i];
                    j++;
                }

            }
        }
        s1[j]=NULL;
        l2 = strlen(s1);

        for(i = 0,k=l2-1; i < l2,k>=0; i++,k--)
        {
            s3[k] = s1[i];
        }
        s3[i]=NULL;

        if(strcmp(s1,s3)==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
