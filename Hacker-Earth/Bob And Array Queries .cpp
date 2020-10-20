#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 500001

ll tree[4 * mx], a[mx];
ll n, q, type, ind;

void update(ll node, ll st, ll ed, ll ind)
{
	if (ind < st || ind > ed)
		return;
	if (ind == st && ind == ed)
	{
		if (type == 1)
		{
			a[ind] += 1;
			tree[node] += 1;
		}
		else
		{
			if (a[ind] == 0)
				return;
			a[ind]--;
			tree[node]--;
		}
		return;
	}
	ll left = 2 * node;
	ll right = 2 * node + 1;
	ll mid = (st + ed) / 2;

	update(left, st, mid, ind);
	update(right, mid + 1, ed, ind);

	tree[node] = tree[left] + tree[right];
}
ll query(ll node, ll st, ll ed, ll i, ll j)
{
	if (j < st || i > ed)
		return 0;
	if (st >= i && ed <= j)
		return tree[node];
	ll left = 2 * node;
	ll right = 2 * node + 1;
	ll mid = (st + ed) / 2;

	ll p1 = query(left, st, mid, i, j);
	ll p2 = query(right, mid + 1, ed, i, j);

	return p1 + p2;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> q;

	W(q)
	{
		cin >> type;
		if (type == 1 || type == 2)
		{
			cin >> ind;
			update(1, 1, n, ind);
		}
		else
		{
			ll i, j; cin >> i >> j;
			cout << query(1, 1, n, i, j) << endl;
		}
	}

	return 0;
}