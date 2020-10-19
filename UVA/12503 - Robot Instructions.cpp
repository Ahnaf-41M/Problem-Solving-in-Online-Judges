#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main()
{
    int i,l,t,n,p,x;
    string s,s1;
    vector<string> v;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        p=0;

        while(n--)
        {
            cin>>s;
            if(s=="SAME")
            {
                 cin>>s1>>x;
            }

            if(s=="RIGHT")
            {
                p++;
                v.push_back(s);
            }
            else if(s=="LEFT")
            {
                p--;
                v.push_back(s);
            }
            else
            {
                if(v[x-1]=="RIGHT")
                {
                    p++;
                    v.push_back("RIGHT");
                }
                else
                {
                    p--;
                    v.push_back("LEFT");
                }
            }

        }
        printf("%d\n",p);
        v.clear();
    }
}
