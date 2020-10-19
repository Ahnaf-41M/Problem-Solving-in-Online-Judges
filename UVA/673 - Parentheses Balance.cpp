#include<bits/stdc++.h>

using namespace std;


int main()
{
  //  IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int i,t;

    cin>>t;
    getc(stdin);

    while(t--)
    {
        char s[200];
        gets(s);
        int l = strlen(s);

        stack<char> stk;
        bool ok = true;

        for(i = 0; i < l; i++)
        {
            if(s[i]=='[' || s[i] == '(')
                stk.push(s[i]);
            else if(s[i]==']')
            {
                if(stk.empty() || stk.top()!='[')
                {
                   // ok = false;
                    stk.push('k');
                    break;
                }
                else
                    stk.pop();

            }
            else if(s[i]==')')
            {
                if(stk.empty() || stk.top()!='(')
                {
                    //ok = false;
                    stk.push('k');
                    break;
                }
                else
                    stk.pop();
            }

        }

        if(stk.empty())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}

