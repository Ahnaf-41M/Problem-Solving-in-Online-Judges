#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 100005

int main()
{
    string s;
    string c1,c2;
    ll t,a,b,n,i,c;
    scanf("%lld",&t);

    for(i = 1; i <= t; i++)
    {
        scanf("%s",&s);
        scanf("%lld",&n);
        printf("Case %lld:\n",i);
        while(n--)
        {
            scanf("%s",&c1);
            if(c1[0]=='I')
            {
                scanf("%lld %lld",&a,&b);
                string temp;
                temp[0] = s[a-1];
                s[a-1] = s[b-1];
                s[b-1] = temp[0];

            }
            else
            {
                scanf("%lld",&c);
                printf("%c\n",s[c-1]);
            }
        }

    }
}
