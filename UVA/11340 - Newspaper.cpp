#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
    int n,m,k,i,j,val,cval;
    double sum=0;
    string s;
    char c;
    map<char,int> mp;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&k);
        c = getchar();
        sum=0;
        for(i = 0; i < k; i++)
        {
            c = getchar();
            scanf("%d",&val);
            mp[c] = val;
            c = getchar();
        }
        scanf("%d",&m);
        c = getchar();
        for(i = 0; i < m; i++)
        {
            getline(cin,s);
            for(j = 0; j < s.size(); j++)
            {
                sum=sum+mp[s[j]];
            }
        }

        sum/=100;
        printf("%.2lf$\n",sum);
       // memset(ch,0,sizeof(ch));
       mp.clear();

    }

}
