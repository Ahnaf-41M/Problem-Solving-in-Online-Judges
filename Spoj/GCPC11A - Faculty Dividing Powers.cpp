#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         1000005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int ok[MX];
vector<int> v;

void Sieve()
{
	for (int i = 3; i < MX; i += 2) ok[i] = 1;
	for (int i = 3; i < MX; i += 2) {
		for (int j = i * i; j < MX; j += i) {
			ok[j] = 0;
		}
	}
	v.pb(2);
	for (int i = 3; i < MX; i++) if (ok[i]) v.pb(i);
}
void Solve(int tc)
{
	int n, k, m;
	vector<PII> pDivs;

	cin >> n >> k;
	m = k;
	for (int d : v) {
		if (d * d > m) break;
		int cnt = 0;
		while (m % d == 0)
			m /= d, cnt++;
		if (cnt) pDivs.pb({cnt, d});
	}
	if (m > 1) pDivs.pb({1, m});

	int ans = 2e18;
	for (auto it : pDivs) {
		int d = it.ss, p = it.ff, curAns = 0;
		int tmpN = n;

		while (tmpN) {
			curAns += tmpN / d;
			tmpN /= d;
		}
		curAns /= p;
		ans = min(ans, curAns);
	}

	cout << ans << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Sieve();
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

}