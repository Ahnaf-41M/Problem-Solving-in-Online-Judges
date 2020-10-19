#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
     ll n,m,x;

     while(scanf("%lld%lld",&n,&m) && n!=0 && m!=0)
     {
          set<ll> s;
          for(int i = 0; i < n; i++)
          {
               scanf("%lld",&x);
               s.insert(x);
          }
          for(int i = 0; i < m; i++)
          {
               scanf("%lld",&x);
               s.insert(x);
          }
          cout<<(m+n)-s.size()<<endl;

     }
}
