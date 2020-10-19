#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define m 1000003
ll a[m];
void fact()
{
    ll i,j;
    a[0]=1;
    for(i = 1; i <= m-1; i++)
    {
         a[i]=((a[i-1]%m)*i)%m;
    }
}

int main()
{
     fact();
	ll n,k,t,i;
	cin>>t;
	for(i = 1; i <= t; i++)
     {
          cin>>n>>k;
          cout<<"Case "<<i<<": "<<a[n]/(a[k]*a[n-k])<<endl;
     }
}

