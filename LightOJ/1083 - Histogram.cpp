#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      30005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
#define  all(v)          v.begin(),v.end()
#define  ZERO(a)         memset(a,0,sizeof(a))
#define  MINUS(a)        memset(a,-1,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

ll a[MX];

ll max_rect_area(ll n)
{
	ll i = 0;
	stack<ll> stk;

	ll mx_area = 0;

	while (i < n)
	{
		if (stk.empty() || a[stk.top()] <= a[i])
			stk.push(i++);
		else
		{
			ll tp = stk.top(); stk.pop();
			ll cur_mx = 0;
			if (stk.empty())
				cur_mx = i * a[tp];
			else
				cur_mx = (i - stk.top() - 1) * a[tp];
			mx_area = max(cur_mx, mx_area);
		}
	}
	while (!stk.empty())
	{
		ll tp = stk.top(); stk.pop();
		ll cur_mx = 0;
		if (stk.empty())
			cur_mx = i * a[tp];
		else
			cur_mx = a[tp] * (i - stk.top() - 1);
		mx_area = max(cur_mx, mx_area);
	}
	return mx_area;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, k, i, j;

	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		ll n;
		scanf("%lld", &n);
		rep(i, 0, n) scanf("%lld", &a[i]);

		printf("Case %d: %lld\n", k, max_rect_area(n));
	}
}