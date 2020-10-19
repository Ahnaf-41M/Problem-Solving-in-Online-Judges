#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,i,m,n,ans=0;
     cin>>t;

     for(i = 1; i <= t; i++)
     {
          cin>>m>>n;
          if(n==1)
               ans = m;
          else if(m==1)
               ans = n;
          else if(n==2)
          {
               ans = (m/4)*4;
               if(m%4==1)
                    ans+=2;
               else if(m%4>1)
                    ans+=4;
          }
          else if(m==2)
          {
               ans = (n/4)*4;
               if(n%4==1)
                    ans+=2;
               else if(n%4>1)
                    ans+=4;
          }
          else
          {
               ans = ((n*m)+1)/2;
          }
          printf("Case %d: %d\n",i,ans);
     }
}
