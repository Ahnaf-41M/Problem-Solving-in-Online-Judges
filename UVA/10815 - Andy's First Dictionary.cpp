#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char ch;
    set<string> sts;
    set<string>::iterator it;

    while(cin>>s)
    {

        string current="";

        for(int i = 0; i < s.size(); i++)
        {
             ch = tolower(s[i]); /*converting the character into lower case as asked..*/
             if(ch>='a' && ch<='z') /*checking if the character is in between a and z and add to current if it is true*/
               current+=ch;

             else if(current != "") /*check if the current string is empty or not..*/
             {
                  sts.insert(current);
                  current="";
             }
        }
        if(current != "")
          sts.insert(current);
    }
    for(it = sts.begin(); it!=sts.end(); it++)
     cout<<(*it)<<endl;
}
