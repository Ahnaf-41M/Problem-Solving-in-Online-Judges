#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
     ll n;
     ll cnt=0,i;

     while(scanf("%lld",&n) && n!=0)
     {
          if(floor(sqrt(n))==ceil(sqrt(n)))
               printf("yes\n");
          else
               printf("no\n");
     }
}
