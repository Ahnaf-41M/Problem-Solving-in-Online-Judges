#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
     ll i,n,k;
     cin>>n;
     ll a[n];

     for(i = 0; i < n; i++)cin>>a[i];
     cin>>k;
     for(i = 0; i < n; i++)
     {
          if(a[i]==k)
          {
               cout<<i<<endl;
               return 0;
          }
     }
}
