#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,n) for(i = 0; i < n; i++)

int main()
{
     ll x,y,n,i,s=1,c=0;
     cin>>x>>y;
     cin>>n;
     ll a[n];
     fr(i,n)cin>>a[i];
     s = x;
     fr(i,n)
     {
          s = (s*a[i])%100000;
          c++;
          if(s>=y)
               break;
     }
     cout<<c<<endl;

}
