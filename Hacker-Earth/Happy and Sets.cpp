#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      100005
#define inf     1000000
#define mod     1000000007
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main()
{
	IOS
	ll n, i, ans = 1, x;

	cin >> n;
	rep(i, 0, n) {
		cin >> x;
	//for set (x,y,z) ,sum = (x+1)*(y+1)*(z+1)-1.
		ans = (ans % mod * (x + 1) % mod) % mod;
	}
	cout<<ans-1<<endl;
}