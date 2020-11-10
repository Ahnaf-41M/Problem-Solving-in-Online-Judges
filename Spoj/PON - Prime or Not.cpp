#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  ull     unsigned long long int
#define  MX      100005
#define  inf     INT_MAX
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  all(v)          v.begin(),v.end()
#define  clr(a,x)        memset(a,x,sizeof(a))
#define  rep(i,a,b)      for(i = a; i <= b; i++)
#define  irep(i,b,a)     for(i = b; i >= a; i--)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

//for calculating (a*b)%c
ll mulmod(ll a, ll b, ll c)
{
	ll x = 0, y = a % c;

	while (b)
	{
		if (b & 1)
			x = (x + y) % c;
		y = (y * 2ll) % c;
		b >>= 1;
	}
	return x % c;
}
//for calculating (a^d)% n
ll Power(ll a, ll d, ll n)
{
	ll res = 1;
	a %= n;
	while (d)
	{
		if (d & 1)
			res = mulmod(res, a, n);
		a = mulmod(a, a, n);
		d >>= 1;
	}
	return res;
}
bool Composite(ll n, ll a, ll d, ll s)
{
	ll x = Power(a, d, n); //a^d % n

	if (x == 1 || x == n - 1)
		return false;

	for (int j = 1; j < s; j++) {
		x = mulmod(x, x, n);
		if (x == n - 1)
			return false;
	}
	return true;
}
bool Miller_Rabin(ll n)
{
	if (n <= 4)
		return n == 2 || n == 3;
	if (n % 2 == 0)
		return false;

	ll s = 0;
	ll d = n - 1;

	while (d % 2 == 0)
		d >>= 1, s++;

	for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (a == n)
			return true;
		if (Composite(n, a, d, s))
			return false;
	}
	return true;
}
int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif

	IOS
	ll n, t;
	cin >> t;

	W(t)
	{
		cin >> n;
		if (Miller_Rabin(n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
