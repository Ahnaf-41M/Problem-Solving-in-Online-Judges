#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j;
    string cur="",s;

    while(cin>>s)
    {
        list<string> Beiju_Text,Normal_Text;
        list<string>::iterator it;
        cur="";
        bool flag = false;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i]!='[' && s[i]!=']')
            {
                cur+=s[i];
            }
            if(s[i]=='[')
            {
                if(flag && cur.size()!=0) /*We will add string to beiju if and only if there is a '[' before the string..*/
                    Beiju_Text.push_front(cur); /*flag indicates whether there is '[' or ']'..*/
                else if(cur.size()!=0)
                    Normal_Text.push_back(cur);
                cur="";
                flag = true;
                continue;
            }
            if(s[i]==']')
            {
                if(flag && cur.size()!=0) /*We will add string to beiju if and only if there is a '[' before the string*/
                    Beiju_Text.push_front(cur); /*flag indicates whether there is '[' or ']'..*/
                else if(cur.size()!=0)
                    Normal_Text.push_back(cur);
                cur="";
                flag = false;
                continue;
            }
        }
        if(flag && cur.size()!=0)
            Beiju_Text.push_front(cur);
        else if(cur.size()!=0)
            Normal_Text.push_back(cur);
        for(it = Beiju_Text.begin(); it!=Beiju_Text.end(); it++)
            cout<<(*it);
        for(it = Normal_Text.begin(); it!=Normal_Text.end(); it++)
            cout<<(*it);
        cout<<'\n';
    }


}
