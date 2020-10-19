#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
     IOS
     int n,i,c=0,j,len;
     string s;

     cin>>n;

     while(n--)
     {
          cin>>s;
          len = s.size();
          c=0;
          for(i = 0,j=len-1; i < len,j>=0; i++,j--)
          {
               if(s[i]!=s[j])
               {
                    c=1;
                    break;
               }
          }
          if(c==1)
               cout<<"NO\n";
          else
               cout<<"YES\n";
     }
}
