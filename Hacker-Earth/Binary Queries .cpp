#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int main()
{
     int n,q,l,r,x,i,j,c=0;

     cin>>n>>q;
     for(i = 1; i <= n; i++)cin>>a[i];

     while(q--)
     {
          cin>>r;
          if(r==1)
          {
               cin>>x;
               if(a[x]==0)
                    a[x]=1;
               else
                    a[x]=0;
          }
          else
          {
               cin>>l>>r;

               if(a[r]&1)
                    cout<<"ODD\n";
               else
                    cout<<"EVEN\n";
          }
     }
}
