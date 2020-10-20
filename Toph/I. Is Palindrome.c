#include<stdio.h>
int main()
{
    char s1[100],s2[100];

    int i=0,j,l=0;

    gets(s1);

    while(s1[i]!='\0')
    {
        i++;
        l++;
    }
    for(j=0,i=l-1;i>=0;i--,j++)
    {
        s2[j]=s1[i];
    }
    s2[j]='\0';
    int d = strcmp(s1,s2);

    if(d==0)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
