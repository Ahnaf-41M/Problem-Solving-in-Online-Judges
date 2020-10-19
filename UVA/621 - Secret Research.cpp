#include<cstdio>
#include<cstring>
using namespace std;


int main()
{

    char s[2000];
    int n,l;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        l = strlen(s);
        if(strcmp(s,"1")==0||strcmp(s,"4")==0||strcmp(s,"78")==0)
        {
            printf("+");
            printf("\n");
        }
        else if(s[l-1]=='5'&&s[l-2]=='3')
        {
            printf("-");
            printf("\n");
        }
        else if(s[0]=='9'&&s[l-1]=='4')
        {
            printf("*");
            printf("\n");
        }
        else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0')
        {
            printf("?");
            printf("\n");
        }
        else
        {
            printf("+");
            printf("\n");
        }
    }

}
