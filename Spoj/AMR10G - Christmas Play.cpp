#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,t,i,k,mn;

     scanf("%d",&t);

     while(t--)
     {
          cin>>n>>k;
          int a[n];
          for(i = 0; i < n; i++)cin>>a[i];
          if(k==1)
               cout<<0<<endl;
          else
          {
               sort(a,a+n);
               mn = INT_MAX;
               for(i = 0; i+k <= n; i++)
               {
                    mn = min(mn,a[i+k-1]-a[i]);
               }
               cout<<mn<<endl;
          }
     }
}
