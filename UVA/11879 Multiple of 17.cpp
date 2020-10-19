#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long p,i;

    while(cin>>s && s[0]!='0')
    {
        long l = s.size();
        p=0;

        for(i = 0; i < l; i++)
        {
            p = (p*10 + (s[i]-'0'))%17;
        }
        if(p==0)cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;


}
