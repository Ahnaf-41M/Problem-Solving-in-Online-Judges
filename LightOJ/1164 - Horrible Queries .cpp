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

struct Segtree
{
	ll sum, prop;
};

Segtree tree[4 * MX];
ll a[MX], n, q;

void update(ll node, ll b, ll e, ll L, ll R, ll val)
{
	if (b > R || e < L) return;

	if (b >= L && e <= R) {
		tree[node].sum += (e - b + 1) * val;
		tree[node].prop += val;
		return;
	}
	ll left = node << 1;
	ll right = (node << 1) + 1;
	ll mid = (b + e) >> 1;

	update(left, b, mid, L, R, val);
	update(right, mid + 1, e, L, R, val);

	tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}
ll Query(ll node, ll b, ll e, ll L, ll R, ll carry)
{
	if (b > R || e < L) return 0;

	if (b >= L && e <= R) {
		return tree[node].sum + (e - b + 1) * carry;
	}
	ll left = node << 1;
	ll right = (node << 1) + 1;
	ll mid = (b + e) >> 1;

	ll p1 = Query(left, b, mid, L, R, carry + tree[node].prop);
	ll p2 = Query(right, mid + 1,e, L, R, carry + tree[node].prop);

	return p1 + p2;
}
int main()
{
	ll t, i, j, k;
	ZERO(a);
	scanf("%lld", &t);

	rep(k, 1, t + 1)
	{
		scanf("%lld%lld", &n, &q);

		printf("Case %lld:\n", k);
		W(q)
		{
			ll type; scanf("%lld", &type);

			if (type == 0) {
				ll x, y, v; scanf("%lld%lld%lld", &x, &y, &v);
				x++,y++;
				update(1, 1, n, x, y, v);
			}
			else {
				ll x, y; scanf("%lld%lld", &x, &y);
				x++,y++;
				printf("%lld\n", Query(1, 1, n, x, y, 0ll));
			}
		}
		ZERO(tree);
	}
}