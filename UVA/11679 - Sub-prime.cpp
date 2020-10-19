#include<bits/stdc++.h>
using namespace std;

int main()
{
     int b,n,c,d,v,sum=0,i,j;
     int r[30];

     while(scanf("%d%d",&b,&n) && n!=0 && b!=0)
     {
          bool check=true;
          sum=0;
          for(i = 0; i < b; i++)scanf("%d",&r[i]);

          while(n--)
          {
               scanf("%d%d%d",&d,&c,&v);
               r[d-1]-=v;
               r[c-1]+=v;
          }
          for(i = 0; i < b; i++)
          {
               if(r[i]<0)
                    check=false;
          }
          if(check)
               printf("S\n");
          else
               printf("N\n");
     }
}
