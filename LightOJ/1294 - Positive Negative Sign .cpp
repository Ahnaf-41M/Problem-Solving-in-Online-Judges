#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
     ll n,m,i,t;
     cin>>t;

     for(i = 1; i <= t; i++)
     {
          cin>>n>>m;
          printf("Case %lld: %lld\n",i,(n*m)/2);
     }
}
