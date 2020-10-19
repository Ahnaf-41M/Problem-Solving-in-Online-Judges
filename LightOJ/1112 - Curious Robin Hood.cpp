#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      100005
#define inf     1000000
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

ll tree[4 * MX];
ll a[MX];

void build(int node, int b, int e)
{
	if (b == e) {
		tree[node] = a[b];
		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	build(left, b, mid);
	build(right, mid + 1, e);

	tree[node] = tree[left] + tree[right];
}
void update(int node, int b, int e, int ind, int type)
{
	if (b > ind || e < ind)
		return;
	if (b >= ind && e <= ind) {
		tree[node] = a[ind];
		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	update(left, b, mid, ind, type);
	update(right, mid + 1, e, ind, type);

	tree[node] = tree[left] + tree[right];

}
ll Query(int node, int b, int e, int l, int r)
{
	if (b > r || e < l)
		return 0;
	if (b >= l && e <= r)
		return tree[node];

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	ll p1 = Query(left, b, mid, l, r);
	ll p2 = Query(right, mid + 1, e, l, r);

	return p1 + p2;
}
int main()
{
	int t, i, j;
	scanf("%d", &t);

	rep(i, 1, t + 1)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		rep(j, 1, n + 1) scanf("%d", &a[j]);
		build(1, 1, n);

		printf("Case %d:\n", i);
		W(m)
		{
			int type; scanf("%d", &type);

			if (type == 1) {
				int ind; scanf("%d", &ind);
				ind++;
				printf("%lld\n", a[ind]);
				a[ind] = 0;
				update(1, 1, n, ind, type);
			}
			else if (type == 2) {
				int ind, val; scanf("%d%d", &ind, &val);
				ind++; a[ind] += val;
				update(1, 1, n, ind, type);
			}
			else {
				int l, r; scanf("%d%d", &l, &r);
				l++, r++;
				printf("%lld\n", Query(1, 1, n, l, r));
			}
		}
	}
}