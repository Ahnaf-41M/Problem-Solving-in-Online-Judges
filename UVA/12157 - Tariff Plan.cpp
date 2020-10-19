#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,t,i,mile,juice,x,j;

     scanf("%d",&t);

     for(i = 1; i <= t; i++)
     {
          scanf("%d",&n);
          mile=0,juice=0;

          for(j = 1; j <= n; j++)
          {
               scanf("%d",&x);
               mile+=(x/30)*10+10;
               juice+=(x/60)*15+15;
          }
          if(mile<juice)
               printf("Case %d: Mile %d\n",i,mile);
          else if(mile==juice)
               printf("Case %d: Mile Juice %d\n",i,juice);
          else
               printf("Case %d: Juice %d\n",i,juice);
     }


}
