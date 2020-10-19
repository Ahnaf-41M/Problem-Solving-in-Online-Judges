#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,wrong=0,dis=0;
    bool Visited[26],guessed[26];
    string s1,s2;
    string::iterator it;

    while(scanf("%d",&t)&&t!=-1)
    {
        cin>>s1>>s2;
        dis=0,wrong=0;

        for(i = 0; i < 26; i++)
        {
            Visited[i]=false;
            guessed[i]=false;
        }
        for(it = s1.begin(); it != s1.end(); it++)
        {
            if(!Visited[*it-'a'])
            {
                Visited[*it-'a'] = true;
                dis++;
            }
        }
        for(it = s2.begin(); it != s2.end(); it++)
        {
            if(wrong==7)
                break;
            if(dis==0)
                break;
            if(Visited[*it-'a'])
            {
                Visited[*it-'a'] = false;
                dis--;
                guessed[*it-'a'] = true;
            }
            else if(!guessed[*it-'a'])
            {
                guessed[*it-'a'] = true;
                wrong++;
            }
        }
        if(dis==0)
            printf("Round %d\nYou win.\n",t);
        else if(wrong==7)
            printf("Round %d\nYou lose.\n",t);
        else
            printf("Round %d\nYou chickened out.\n",t);
    }
}
