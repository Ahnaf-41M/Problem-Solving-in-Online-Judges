#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,m,i,j;
     set<int> s;
     set<int>::iterator it;

     cin>>n;
     int a[n];

     for(i = 0; i < n; i++)cin>>a[i];
     cin>>m;
     int b[m];
     for(i = 0; i < m; i++)cin>>b[i];

     for(i = 0; i < n; i++)
     {
          for(j = 0; j < m; j++)
          {
               int f = abs(a[i]-b[j]);
               s.insert(f);
          }
     }
     for(it = s.begin(); it!=s.end(); it++)
          cout<<*it<<" ";
     cout<<endl;
}
