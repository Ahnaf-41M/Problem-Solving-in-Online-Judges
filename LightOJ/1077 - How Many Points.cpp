#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll t,a,b,c,d,i;
     cin>>t;

     for(i = 1; i <= t; i++)
     {
          cin>>a>>b>>c>>d;
          printf("Case %lld: %lld\n",i,__gcd(abs(a-c),abs(b-d))+1);
     }
}
