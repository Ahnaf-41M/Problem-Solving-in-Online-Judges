#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

void solve(ll n)
{
     ll i,j,cnt=0;

     while(n%2==0)
     {
          n/=2;
          cnt++;
     }
     if(cnt>0)
          cout<<2<<"^"<<cnt<<" ";
     for(i = 3; i*i <= n; i+=2)
     {
          cnt=0;
          while(n%i==0)
          {
               n/=i;
               cnt++;
          }
          if(cnt>0)
               cout<<i<<"^"<<cnt<<' ';
     }
     if(n>2)
          cout<<n<<"^"<<1;
     cout<<endl;
}
int main()
{
     ll n;
     while(cin>>n,n)
     {
          solve(n);
     }
}


