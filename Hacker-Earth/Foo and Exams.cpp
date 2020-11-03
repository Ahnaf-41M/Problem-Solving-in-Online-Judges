#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     INT_MAX
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  all(v)          v.begin(),v.end()
#define  clr(a,x)        memset(a,x,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  irep(i,a,b)     for(i = a; i >= b; i--)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;
ll t, a, b, c, d, k;

ll Foo_funtion(ll m)
{
	return a * m * m * m + b * m * m + c * m + d;
}
ll BSearch(ll kk)
{
	ll low = 0, high = kk;

	while (low <= high)
	{
		ll mid = (low + high) / 2;
		ll x = Foo_funtion(mid);
		ll y = Foo_funtion(mid + 1);

		if (x <= k && y > k)
			return mid;
		if (x > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
}
int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif
	IOS

	cin >> t;

	W(t)
	{
		cin >> a >> b >> c >> d >> k;
		ll kk = cbrt(k) + 1; //as the function has t^3
		cout << BSearch(kk) << endl;
	}
}