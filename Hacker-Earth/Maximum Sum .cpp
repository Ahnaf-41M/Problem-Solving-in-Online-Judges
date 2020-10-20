#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
     ll i,n,mx,cnt=0,sum=0;
     cin>>n;
     ll a[n];
     for(i = 0; i < n; i++)cin>>a[i];

     sort(a,a+n);
     for(i = n-1; i >= 0; i--)
     {
          if(a[i]<0 && i==n-1)
          {
               cnt++;
               sum+=a[i];
               break;
          }
          else
          {
               if(a[i]<0)
                    break;
               else
               {
                    sum+=a[i];
                    cnt++;
               }
          }
     }
     cout<<sum<<" "<<cnt<<endl;
}
