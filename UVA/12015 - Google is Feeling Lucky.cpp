#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,i,mx=0,x,j;
     string s;

     vector<int> v;
     vector<string> vs;

     scanf("%d",&n);

     for(i = 1; i <= n; i++)
     {
          mx = -1;
          for(j = 1; j <= 10; j++)
          {
               cin>>s>>x;
               v.push_back(x);
               vs.push_back(s);
               if(mx<x)
                    mx=x;
          }

          printf("Case #%d:\n",i);
          for(j = 0; j < v.size(); j++)
          {
               if(v[j]==mx)
                    cout<<vs[j]<<"\n";
          }
          v.clear();
          vs.clear();
     }
}
