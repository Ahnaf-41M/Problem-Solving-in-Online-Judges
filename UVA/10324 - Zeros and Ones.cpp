#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n,j,k,i,tc=1;
    bool one,zero;

    while(cin>>s)
    {
         int d,e;
        scanf("%d",&n);
        printf("Case %d:\n",tc);
        while(n--)
        {
            scanf("%d %d",&j,&k);
            one = false;
            zero = false;
            d = min(j,k);
            e = max(j,k);
            for(i = d; i <= e; i++)
            {
                if(s[i]=='1')
                    one = true;
                if(s[i]=='0')
                    zero = true;
                if(one && zero)
                    break;
            }
            if(one && zero)
                printf("No\n");
            else
                printf("Yes\n");

        }
        tc++;
    }


}
