#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     string s;

     while(cin>>s)
     {
          int l = s.size(),i,j,k,m;
          map<string,int> mp;
          string tmp;
          int cnt=0;

          for(i = 0; i < l; i++)
          {
               for(j = 1; j <= l-i; j++)
               {
                    tmp = s.substr(i,j);
                    bool ok = true;
                    for(k = 0,m = tmp.size()-1; k < tmp.size(),m>=0;k++,m--)
                    {
                         if(tmp[k]!=tmp[m])
                         {
                              ok = false;
                              break;
                         }
                    }
                    if(ok && !mp[tmp])
                    {
                         mp[tmp]++;
                         cnt++;
                    }

               }
          }
          cout<<"The string '"<<s<<"' contains "<<cnt<<" palindromes."<<endl;
     }
}
