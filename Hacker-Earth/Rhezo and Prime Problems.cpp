#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      5005
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

ll pre[MX], a[MX], dp[MX];
vector<int> primes;
bool vis[MX];

inline void sieve()
{
	primes.pb(2);

	for (int i = 3; i < MX; i += 2) {
		if (!vis[i]) {
			primes.pb(i);
			for (int j = i + i; j < MX; j += i) {
				vis[j] = true;
			}
		}
	}
}

int main()
{
	IOS

	sieve();
	int n, i, j;

	cin>>n;
	rep(i, 1, n + 1) cin >> a[i];

	rep(i, 1, n + 1) pre[i] = pre[i - 1] + a[i];

	rep(i, 2, n + 1) {
		dp[i] = dp[i - 1];
		rep(j, 0, primes.size()) {
			if (primes[j] > i) break;

			int idx = i - primes[j] - 1;

			if (idx == -1) dp[i] = max(dp[i], pre[i] - pre[idx + 1]);
			else dp[i] = max(dp[i], dp[idx] + pre[i] - pre[idx + 1]);
		}
	}
	cout << dp[n] << endl;
}