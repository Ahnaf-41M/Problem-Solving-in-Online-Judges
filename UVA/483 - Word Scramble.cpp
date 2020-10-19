#include<bits/stdc++.h>
using namespace std;

int main()
{
    int st,ed,i;
    string s;

    while(getline(cin,s))
    {
        for(i = 0; i < s.size(); i++)
        {
            if(i==0)
                st=i;
            if(s[i-1]==' ' &&i!=0)
            {
                st=i;
                //ed=i;
            }
            else if(s[i]==' ' || i==s.size()-1)
            {
                 if(i!=s.size()-1)
                reverse(s.begin()+st,s.begin()+i);
                else
                    reverse(s.begin()+st,s.end());
            }

        }
        cout<<s<<endl;
    }
}
