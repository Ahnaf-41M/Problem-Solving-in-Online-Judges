#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> >v(1001);
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
     if(p1.first<p2.first)
          return 1;
     if(p1.first>p2.first)
          return 0;
     if(p1.second>p2.second)
          return 1;
     return 0;
}
void div()
{
     int i,j;
     for(i = 1; i <= 1000; i++)
     {
          v[i].first = 0;
          v[i].second = i;
     }
     for(i = 1; i <= 1000; i++)
     {
          for(j = i; j <= 1000;j+=i)
               v[j].first++;
     }
     sort(v.begin(),v.end(),cmp);
}

int main()
{
    div();
    int i,n,t;
    cin>>t;


    for(i = 1; i <= t; i++)
    {
         cin>>n;
         printf("Case %d: %d\n",i,v[n].second);
    }
}
