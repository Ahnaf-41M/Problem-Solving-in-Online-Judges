#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
         int c=0;
        if(s[0]=='#')
            break;

        while(next_permutation(s.begin(),s.end()))
        {
             c++;
             if(c==1)
               break;
        }
        if(c==1)
          cout<<s<<'\n';
        else
          printf("No Successor\n");

    }
}
