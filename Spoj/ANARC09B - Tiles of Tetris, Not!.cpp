#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define ll long long
int main()
{
     ll n,m,ans;

     while(cin>>n>>m && n!=0 && m!=0)
     {
          ans = (lcm(n,m)/gcd(n,m));
          cout<<ans<<endl;
     }
}
