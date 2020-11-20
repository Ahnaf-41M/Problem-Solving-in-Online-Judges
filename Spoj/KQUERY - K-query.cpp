#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  ll   long long
#define  endl "\n"
#define  MX   30005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(ll i = a; i <= b; i++)

using namespace std;
using namespace __gnu_cxx;

int a[MX], n, q, k;
vector<int> segTree[4*MX];

void build(int node, int b, int e)
{
	if (b == e) {
		segTree[node].pb(a[b]);
		return;
	}

	int mid = (b + e) / 2;
	int left = node << 1;
	int right = (node << 1) + 1;

	build(left, b, mid);
	build(right, mid + 1, e);

	int i = 0, j = 0;

	while (i < segTree[left].size() && j < segTree[right].size()) {
		if (segTree[left][i] <= segTree[right][j])
			segTree[node].pb(segTree[left][i]), i++;
		else
			segTree[node].pb(segTree[right][j]), j++;
	}
	while (i < segTree[left].size())
		segTree[node].pb(segTree[left][i]), i++;
	while (j < segTree[right].size())
		segTree[node].pb(segTree[right][j]), j++;
}
int Query(int node, int b, int e, int l, int r, int k)
{
	if (b > r || e < l) return 0;

	if (b >= l && e <= r) {
		int indx = upper_bound(all(segTree[node]), k) - segTree[node].begin();
		if (indx == segTree[node].size()) return 0;
		else return (segTree[node].size() - indx);
	}
	int mid = (b + e) / 2;
	int left = node << 1;
	int right = (node << 1) + 1;

	int r1 = Query(left, b, mid, l, r, k);
	int r2 = Query(right, mid + 1, e, l, r, k);

	return r1 + r2;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> a[i];
	build(1, 1, n);

	cin >> q;

	W(q)
	{
		int l, r, k; cin >> l >> r >> k;
		cout << Query(1, 1, n, l, r, k) << endl;
	}
	return 0;
}