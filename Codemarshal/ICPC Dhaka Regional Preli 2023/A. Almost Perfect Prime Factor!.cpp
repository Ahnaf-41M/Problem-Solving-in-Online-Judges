#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         1000005
#define  MAXN       100005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int spf[MX], cnt[MX];
int n, k;
int a[MAXN];
struct segment_tree
{
	struct node {
		int suru , ses, gcd;

		void init(int l, int r) {
			suru = l, ses = r;
			if (l == r) gcd = a[l];
		}
	} g[4 * MAXN];


	void build(int cn, int l, int r)
	{
		g[cn].init(l, r);

		if (l == r ) return;
		int md = l + (r - l) / 2;

		build(cn * 2, l, md);
		build(cn * 2 + 1, md + 1, r);

		g[cn].gcd = __gcd(g[cn * 2].gcd, g[cn * 2 + 1].gcd);
	}

	int query(int cn, int l, int r)
	{
		int x = g[cn].suru;
		int y = g[cn].ses;
		if (y < l || x > r) return 0;

		if (l <= x && r >= y ) return g[cn].gcd;

		int ans1 = query(cn * 2 + 1, l, r);
		int ans = query(cn * 2, l, r);
		return __gcd(ans1, ans);
	}

} stre;
void Sieve()
{
	for (int i = 2; i < MX; i++) {
		if (!spf[i]) {
			for (int j = i; j < MX; j += i) {
				if (!spf[j])
					spf[j] = i;
			}
		}
	}
}
void Solve(int tc)
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> a[i];

	stre.build(1, 1, n);

	// cout << stre.query(1, 2, 4) << endl;
	set<int> allPrime;
	int till_k = 0;

	int i = 1, j = 1, len = 0, ans = 0;
	while (j <= n) {
		int x = a[j];
		len = 0;
		while (x > 1) {
			int d = spf[x];
			if (x % d == 0) {
				if (!cnt[d]) till_k++;
				cnt[d]++;
				len = max(len, cnt[d]);
				allPrime.insert(d);
				while (x % d == 0)
					x /= d;
			}

		}

		if (till_k > k) {
			while (i <= j && till_k > k) {
				int x = a[i];
				while (x > 1) {
					int d = spf[x];
					if (x % d == 0) {
						cnt[d]--;
						if (cnt[d] == 0) till_k--;
						while (x % d == 0)
							x /= d;
					}
				}
				i++;
			}
		}
		if (till_k == k) {
			if (stre.query(1, i, j) == 1) ans = max(ans, j - i + 1);
		}
		j++;
	}

	cout << "Case " << tc << ": " << ans << "\n";
	for (int x : allPrime) cnt[x] = 0;
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