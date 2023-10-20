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
	for (int i = 2; i < MX; i++) {
		if (!ok[i]) {
			for (int j = i * i; j < MX; j += i) {
				ok[j] = 1;
			}
		}
	}

	for (int i = 2; i < MX; i++) if (!ok[i]) v.pb(i);
}
void Solve(int tc)
{
	int n;
	set<int> ans;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int d : v) {
			if (d * d > x) break;
			if (x % d == 0) {
				while (x % d == 0)
					x /= d;
				ans.insert(d);
			}
		}
		if (x > 1) ans.insert(x);
	}
	cout << "Case #" << tc << ": " << ans.size() << "\n";
	for (int x : ans) cout << x << "\n";
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