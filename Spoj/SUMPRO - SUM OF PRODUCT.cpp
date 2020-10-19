#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main()
{
     IOS
     ll sum=0,sum2=0,n,t,p,i;

     cin>>t;

     while(t--)
     {
          cin>>n;
          for(i = 1; i <= sqrt(n); i++)
          {
               y = n/i;
               sum+=(y*i);
          }
          p = n-max(y,(i-1));

     }
}
