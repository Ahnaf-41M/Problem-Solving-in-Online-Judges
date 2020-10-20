#include<bits/stdc++.h>
using namespace std;

int main()
{
     int x,y,s,t,i,j,cnt=0;

     cin>>x>>y>>s>>t;

     for(i = x; i <= x+s; i++)
     {
          for(j = y; j <= y+s; j++)
          {
               if((i+j)<=t)
                    cnt++;
          }
     }
     cout<<cnt<<endl;
}

