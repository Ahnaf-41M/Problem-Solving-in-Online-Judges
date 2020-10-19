#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    int t,i,cnt=0,ans=0;
    string s;

    scanf("%d",&t);

    while(t--)
    {
        cin>>s;
        int n=0;        ans=0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i]=='O')
            n++;
            else 
            {
                ans+=(n*(n+1)/2);
                n=0;
            }
        }
        ans+=(n*(n+1)/2);
        printf("%d\n",ans);
    }
}