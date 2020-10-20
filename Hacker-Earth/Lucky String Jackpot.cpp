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
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const ll mx = 1e15;
ll powStored[105];

void pre_process()
{
	ll i;
	powStored[0] = 0;
	rep(i, 1, 100) {
		//Strings of length 1,2,3..n have 1*(2^1), 2*(2^2), 3*(2^3)..n*(2^n) characters
		powStored[i] =  (i << i) + powStored[i - 1];
		if (powStored[i] > mx)
			break;
	}
}
int main()
{
	IOS
	pre_process();

	ll t, n, i, len = 0;
	cin >> t;

	W(t)
	{
		cin >> n;

		rep(i, 1, 100) {
			if (powStored[i] >= n)
				break;
		}
		cout<<i<<" ";
		len = i - 1;
		n -= powStored[i - 1];

		cout << min(n, 2 * len + 1) << endl;
	}
}