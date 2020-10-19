#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,cnt=1,mn;
    string s;



    while(scanf("%d",&t)&& t!=0)
    {
        cin>>s;
        char ch=' ';
        mn = INT_MAX;
        cnt=1;

        for(i = 0; i < t; i++)
        {
             if(s[i]=='Z')
             {
                  mn = 0;
                  break;
             }
             if((s[i]=='D'&& ch=='R')||(s[i]=='R'&&ch=='D'))
             {
                  mn = min(mn,cnt);
                  cnt=1;
                  ch = (s[i]=='D')?'D':'R';
             }
             else if(s[i]=='D'||s[i]=='R')
             {
                  ch = s[i];
                  cnt=1;
             }
             else
               cnt++;

        }
        printf("%d\n",mn);


     }
}
