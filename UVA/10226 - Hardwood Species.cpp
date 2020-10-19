#include<bits/stdc++.h>
using namespace std;

int main()
{
     int cnt=0,i,t,c;
     map<string,int> mp;
     map<string,int>::iterator it;
     string s;
     double ans;
     scanf("%d",&t);
     getchar();
	getchar();
     while(t--)
     {
          //printf("\n");
          cnt=0;
         // cin.ignore();
          while(getline(cin,s))
          {
               if(s.compare("")==0)
                    break;
               else
               {
                    mp[s]++;
                    cnt++;
               }
          }
          for(it = mp.begin();it!=mp.end(); it++)
          {
               c = (*it).second;
               ans = (c*1.0)/(cnt*1.0);
               ans*=100;

               cout<<(*it).first;
               printf(" %.4lf\n",ans);
          }
          if(t>0)
               printf("\n");
          mp.clear();
     }
}
