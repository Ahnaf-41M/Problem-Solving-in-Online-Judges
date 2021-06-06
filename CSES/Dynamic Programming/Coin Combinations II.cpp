#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[MX], mod = 1e9 + 7;
void Solve(int tc)
{
	int n, req;
	cin >> n >> req;
	int ar[n];

	for (int &x : ar)
		cin >> x;

	//dp[i] => number of ways to make value i
	dp[0] = 1;
	for (int val : ar) {
		for (int i = val; i <= req; i++) {
			dp[i] += dp[i - val];
			dp[i] %= mod;
		}
	}
	cout << dp[req];
	return;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	//cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}