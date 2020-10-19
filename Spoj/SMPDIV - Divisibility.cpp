#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
     IOS
     int n,x,y,t,i,j;

     cin>>t;

     while(t--)
     {
          cin>>n>>x>>y;

          for(i = x; i <= n; i+=x)
          {
               if(i%y!=0)
                    cout<<i<<" ";
          }
          cout<<endl;
     }


}
