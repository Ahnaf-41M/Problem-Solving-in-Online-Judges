#include <bits/stdc++.h>
using namespace std;
#define MX     300005
#define pb     push_back
#define int    long long
#define all(v) v.begin(),v.end()

vector<int> segTree[4 * MX], product[4 * MX];
int ar[MX], n, m, done;
int ans = 1;
const int mod = 1e9 + 7;

void build_product(int node)
{
	int cur = 1;
	for (int x : segTree[node]) {
		cur = (cur * x) % mod;
		product[node].pb(cur);
	}
}
void build(int node, int b, int e)
{
	if (b == e) {
		segTree[node].pb(ar[b]);
		product[node].pb(ar[b]);
		return;
	}
	int mid = (b + e) / 2;
	int left = node << 1;
	int right = (node << 1) + 1;

	build(left, b, mid);
	build(right, mid + 1, e);

	merge(all(segTree[left]), all(segTree[right]), back_inserter(segTree[node]));

	build_product(node);
}
void Query(int node, int b, int e, int l, int r, int h)
{
	if (b > r || e < l)
		return;
	if (b >= l && e <= r) {
		int idx = upper_bound(all(segTree[node]), h) - segTree[node].begin();
		idx--;
		if (idx >= 0) ans = (ans * product[node][idx]) % mod;
		return;
	}

	int mid = (b + e) / 2;
	int left = (node << 1);
	int right = (node << 1) + 1;

	Query(left, b, mid, l, r, h);
	Query(right, mid + 1, e, l, r, h);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	build(1, 1, n);


	while ( m-- ) {
		int l, r, h;
		cin >> l >> r >> h; l++, r++;
		Query(1, 1, n, l, r, h);
		cout << ans << "\n";
		ans = 1, done = 0;
	}
}