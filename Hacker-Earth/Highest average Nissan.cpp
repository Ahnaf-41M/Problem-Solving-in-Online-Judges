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
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

ll BSearch(ll b[], ll k, ll n)
{
	ll low = 1, high = n;

	while (low <= high)
	{
		ll mid = (low + high) / 2;
		if (b[mid] < k && b[mid + 1] >= k)
			return mid;

		if (b[mid] >= k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
int main()
{
	IOS
	ll n, q, i, k, sum = 0;
	
	cin >> n;
	ll a[n + 1], b[n + 2];

	rep(i, 1, n + 1) {
		cin >> a[i];
	}
	b[n + 1] = inf;
	sort(a + 1, a + n + 1);
	rep(i, 1, n + 1) {
		sum += a[i];
		b[i] = sum / i;
	}
	cin >> q;
	W(q)
	{
		cin >> k;
		cout << BSearch(b, k, n) << endl;
	}
}
