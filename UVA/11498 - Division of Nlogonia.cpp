#include<bits/stdc++.h>
using namespace std;

int main()
{
     int x,y,n,m,t;

     while(cin>>t && t!=0)
     {
          cin>>n>>m;
          for(int i = 0; i < t; i++)
          {
               cin>>x>>y;
               if(x==n||y==m)
                    cout<<"divisa\n";
               else if(x<n && y>m)
                    cout<<"NO\n";
               else if(x>n && y>m)
                    cout<<"NE\n";
               else if(x<n && y<m)
                    cout<<"SO\n";
               else
                    cout<<"SE\n";
          }
     }
}
