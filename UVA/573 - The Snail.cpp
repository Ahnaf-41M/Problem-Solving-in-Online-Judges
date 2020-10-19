#include<bits/stdc++.h>
using namespace std;

int main()
{
     int h,u,d,f,cnt=0;
     double dc,ff,u1;

     while(scanf("%d%d%d%d",&h,&u,&d,&f)&&h!=0)
     {
          u1 = u*1.0;
          ff = (u1*f*1.0)/100.0;
          dc = 0,cnt=1;
         // u1-=ff;

          while(1)
          {
               dc+=u1;
               if(u1>0)
                    u1-=ff;
               if(dc>h)
                    break;
               dc-=d;
               if(dc<0)
                    break;
               cnt++;
          }
          if(dc>h)
               printf("success on day %d\n",cnt);
          else
               printf("failure on day %d\n",cnt);
     }
}
