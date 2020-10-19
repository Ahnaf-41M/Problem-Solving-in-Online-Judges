#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll t,a,b,gcd,lcm;

     cin>>t;
     while(t--)
     {
          cin>>a>>b;
          gcd = __gcd(a,b);
          lcm = (a*b)/gcd;
          if(gcd==a&&lcm==b)
               cout<<a<<" "<<b<<endl;
          else
               cout<<-1<<endl;
     }
}
