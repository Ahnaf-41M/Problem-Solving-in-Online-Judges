#include<stdio.h>
#include<string.h>

int main()
{
    char s1[1000],s2[1000],s3[1000];
    int i,j,t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s %s",&s1,&s2);

        for(i = 0,j = strlen(s1)-1; i < strlen(s1),j>=0;i++,j--)
        {
            s1[j] = s1[i];
        }
        for(i = 0,j = strlen(s2)-1; i < strlen(s2),j>=0;i++,j--)
        {
            s2[j] = s2[i];
        }

    }
}
