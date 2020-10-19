#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 10000005
bool a[mx+5];
vector<ll> v;

int main()
{
     ll i,j,t,n;
     cin>>t;
     a[0]=a[1]=false;
     for(i = 3; i <= mx; i+=2)
          a[i]=true;
     v.push_back(2);
     for(i = 3; i <= sqrt(mx); i+=2)
     {
          if(a[i])
          {
               for(j = 2; i*j <= mx; j++)
               {
                    a[i*j]=false;
               }
               v.push_back(i);
          }
     }

}

