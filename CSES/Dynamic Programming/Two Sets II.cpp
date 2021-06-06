#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           63000
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[501][MX], n, sum;
int mod = 1e9 + 7;

int call(int pos, int cur)
{
	if (cur == 0) return 1;
	/* pos>=n, because, by only considering numbers up to n-1, we always
	put n in the second set, and therefore only count each pair of sets
	once (otherwise we count every pair of sets twice).*/
	if (cur < 0 || pos >= n) return 0;
	if (dp[pos][cur] != -1) return dp[pos][cur];

	int r1 = call(pos + 1, cur - pos);
	int r2 = call(pos + 1, cur);

	return dp[pos][cur] = ((r1 % mod) + (r2 % mod)) % mod;
}
void Solve(int tc)
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	sum = (n * (n + 1)) / 2;

	if (sum & 1) cout << 0;
	else cout << call(1, sum / 2);

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