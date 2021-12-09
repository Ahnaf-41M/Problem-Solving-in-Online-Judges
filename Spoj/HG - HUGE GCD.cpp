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

vector<int> v;
bool ok[MX];
map<int, int> frq1, frq2;
int mod = 1e9, sz = 1e10 - 1;
void Sieve()
{
	v.pb(2);
	for (int i = 3; i < MX; i += 2) ok[i] = 1;
	for (int i = 3; i < MX; i += 2) {
		if (ok[i]) {
			v.pb(i);
			for (int j = i * i; j < MX; j += i)
				ok[j] = 0;
		}
	}
}
void Fact(int x, map<int, int> &frq)
{
	for (int d : v) {
		if (d * d > x) break;
		while (x % d == 0)
			frq[d]++, x /= d;
	}
	if (x > 1) frq[x]++;
}
void Solve(int tc)
{
	int n, m, ans = 1, lead = 0;
	cin >> n;
	while (n--) {
		int x; cin >> x;
		Fact(x, frq1);
	}
	cin >> m;
	while (m--) {
		int x; cin >> x;
		Fact(x, frq2);
	}

	for (auto it : frq1) {
		int power = min(it.ss, frq2[it.ff]);
		rep(i, 1, power) {
			ans = ans * it.ff;
			if (ans > sz) lead = 1;
			ans %= mod;
		}
	}

	string s = to_string(ans);
	if (lead)
		rep(i, 1, 9 - s.size()) cout << 0;
	cout << s << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Sieve();
	int T = 1;
	// cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}
