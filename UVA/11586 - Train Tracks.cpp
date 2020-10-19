#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,t;
    string s;
    bool chk=true;
    scanf("%d",&t);
    cin.ignore();
    int cnt=0;
    while(t--)
    {
        getline(cin,s);
        chk = true;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i]=='M')
            {
                cnt++;
            }
            else if(s[i]=='F')
            {
                cnt--;
            }
        }
        if(cnt==0 && s.size()>3)
            cout<<"LOOP\n";
        else
            cout<<"NO LOOP\n";
            cnt=0;
    }

}
