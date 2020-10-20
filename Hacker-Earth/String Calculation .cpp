#include<stdio.h>
#include<string.h>

int main()
{
    int i,c,l;
    char s[2000];
    gets(s);

    c=0;

    for(i = 0; s[i]!='\0'; i++)
    {
        if(s[i]=='a'||s[i]=='e'||
                s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            c=c;
        }
        else if(s[i]>='b' && s[i]<='z')
            c++;
        else
            c=c;
    }
    printf("%d\n",c);
}
