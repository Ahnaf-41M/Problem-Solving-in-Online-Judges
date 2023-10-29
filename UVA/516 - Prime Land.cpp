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

int spf[MX];
void sieve()
{
	for (int i = 2; i < MX; i++) {
		if (!spf[i]) {
			for (int j = i; j < MX; j += i) {
				if (!spf[j]) {
					spf[j] = i;
				}
			}
		}
	}

}
void factorization(int x)
{
	vector<PII> res;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0)
			x /= d, cnt++;
		res.pb({d, cnt});
	}

	sort(res.begin(), res.end(), greater<PII>());
	int n = res.size();
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << res[i].ff << " " << res[i].ss;
	}
	cout << "\n";
}
int Pow(int p, int x)
{
	int res = 1;
	while (x) {
		if (x & 1) res = res * p;
		p *= p;
		x >>= 1;
	}
	return res;
}
void Solve(int tc)
{
	string s;
	while (getline(cin, s)) {
		if (s[0] == '0') break;
		int i = 0, num = 1, len = s.size();
		while (i < len) {
			string ps, xs;
			int p, x;
			while (i < len && s[i] != ' ')
				ps.pb(s[i]), i++;
			i++;
			while (i < len && s[i] != ' ')
				xs.pb(s[i]), i++;
			i++;
			p = stoll(ps);
			x = stoll(xs);

			num *= Pow(p, x);
		}
		factorization(num - 1);
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();
	int T = 1;
	//cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

}