#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    IOS

    string s;

    int n,i,j,cnt=0;

    while(cin>>n)
    {
        while(n--)
        {
            cin>>s;
            if (s.size() > 3)
                printf("3\n");
            else
            {
                if(s[0] == 'o' && s[1] == 'n' && s[2] == 'e')
                    printf("1\n");
                else if(s[0] == 'o' && s[1] == 'n')
                    printf("1\n");
                else if(s[0] == 'o' && s[2] == 'e')
                    printf("1\n");
                else if(s[1] == 'n' && s[2] == 'e')
                    printf("1\n");
                else if(s[0] == 't' && s[1] == 'w' && s[2] == 'o')
                    printf("2\n");
                else if(s[0] == 't' && s[1] == 'w')
                    printf("2\n");
                else if(s[0] == 't' && s[2] == 'o')
                    printf("2\n");
                else if(s[1] == 'w' && s[2] == 'o')
                    printf("2\n");
            }
        }
    }
}
