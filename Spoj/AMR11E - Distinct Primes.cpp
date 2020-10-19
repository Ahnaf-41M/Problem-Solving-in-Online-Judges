#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100005
vector<ll> v;
set<ll> s;
void prime_fac()
{
     ll i,j,n;
     v.push_back(30);
     v.push_back(42);

     for(i = 43; i <= mx; i++)
     {
          n = i;
          while(n%2==0)
          {
               n/=2;
               s.insert(2);
          }
          for(j = 3; j <= sqrt(n); j++)
          {
               while(n%j==0)
               {
                    n/=j;
                    s.insert(j);
               }
          }
          if(n>2)
               s.insert(n);
           if(s.size()>=3)
               v.push_back(i);
           s.clear();
     }
}
int main()
{
     prime_fac();
     ll n,t;
     cin>>t;
     while(t--)
     {
          cin>>n;
          cout<<v[n-1]<<endl;
     }
}
