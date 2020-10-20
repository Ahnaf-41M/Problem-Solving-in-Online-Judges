#include<bits/stdc++.h>
using namespace std;

int main()
{
     int c1=0,c2=0,i,t;
     cin>>t;
     string s;
     while(t--)
     {
          cin>>s;
          c1=0;
          c2=0;
          for(i = 0; i < s.size(); i++)
          {
               if(s[i]=='S'&&s[i+1]=='U'&&s[i+2]=='V'&&s[i+3]=='O')
               {
                    c1++;
                    if(s[i+4]=='J'&&s[i+5]=='I'&&s[i+6]=='T')
                    {
                         c1--;
                         c2++;
                    }
               }
          }
          cout<<"SUVO = "<<c1<<", SUVOJIT = "<<c2<<endl;
     }
}
