#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     1000000
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
ll A, B, C, x, k, t;

ll pol_val(ll m)
{
	return A * m * m + B * m + C;
}
ll Find_x()
{
	ll low = 0, high = sqrt(k) + 1;

	while (low <= high)
	{
		ll mid = (low + high) / 2;
		ll y = pol_val(mid);
		ll z = pol_val(mid - 1);

		if (y >= k && z < k)
			return mid;
		if (y > k) high = mid - 1;
		else low = mid + 1;
	}
}
int main()
{
	IOS
	cin >> t;

	W(t)
	{
		cin >> A >> B >> C >> k;
		cout << Find_x() << "\n";
	}
}