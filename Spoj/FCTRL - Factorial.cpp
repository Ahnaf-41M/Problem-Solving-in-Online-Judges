#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

ll fact_o(ll n)
{
     ll i,cnt=0;

     for(i = 5; n/i >= 1; i*=5)
     {
          cnt+=n/i;
     }
     return cnt;
}
int main()
{
     IOS
     ll t,n,zero;

     cin>>t;

     while(t--)
     {
          cin>>n;
          zero = fact_o(n);
          cout<<zero<<endl;
     }
}

