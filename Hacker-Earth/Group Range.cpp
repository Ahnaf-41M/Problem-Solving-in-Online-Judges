#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      100005
#define inf     1000000
#define mod     1000000007
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

map<ll, ll> par, mn_group, mx_group;
ll a[2 * MX];

ll find(ll v)
{
	if (par[v] == v) return v;
	else return par[v] = find(par[v]);
}
void Union(int r1, int r2)
{
	if (a[r1] < a[r2]) {
		par[r1] = r2;
		mx_group[r2] = max(mx_group[r1], mx_group[r2]);
		mn_group[r2] = min(mn_group[r1], mn_group[r2]);
	}
	else {
		par[r2] = r1;
		mx_group[r1] = max(mx_group[r1], mx_group[r2]);
		mn_group[r1] = min(mn_group[r1], mn_group[r2]);
	}
}
int main()
{
	IOS
	ll n, q, i;

	cin >> n;

	rep(i, 1, n + 1) {
		cin >> a[i];
		par[i] = i;
		mn_group[i] = a[i];
		mx_group[i] = a[i];
	}

	cin >> q;

	W(q)
	{
		ll id1, id2; cin >> id1 >> id2;
		// ll x = a[id1], y = a[id2];

		ll r1 = find(id1);
		ll r2 = find(id2);

		if (r1 != r2) {
			Union(r1, r2);
			cout << mn_group[par[r1]] << " " << mx_group[par[r1]] << endl;
		}
		else
		{
			cout << mn_group[par[r1]] << " " << mx_group[par[r1]] << endl;
		}
	}

}