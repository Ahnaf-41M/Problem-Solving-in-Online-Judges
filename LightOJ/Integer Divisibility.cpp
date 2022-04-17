#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

void Solve(int tc)
{
	int n, dig;
	string ans = "";

	cin >> n >> dig;

	int mod = dig;
	ans.pb(dig + '0');
	mod %= n;

	while (mod) {
		mod = mod * 10 + dig;
		mod %= n;
		ans.pb(dig + '0');
	}
	cout << "Case " << tc << ": " << ans.size() << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}