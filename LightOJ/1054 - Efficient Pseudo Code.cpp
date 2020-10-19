#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      300005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
#define  all(v)          v.begin(),v.end()`
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

bool is_prime[MX + 5];
vector<ll> primes;
ll n, m;
inline void sieve()
{
	for (ll i = 3; i <= MX; i += 2)
		is_prime[i] = true;
	for (ll i = 3; i <= sqrt(MX); i += 2)
		if (is_prime[i])
			for (ll j =  i * 2; j <= MX; j += i)
				is_prime[j] = false;
	primes.pb(2);
	for (ll i = 3; i <= MX; i += 2)
		if (is_prime[i])
			primes.pb(i);
}
//Calculating (a^n) % mod
ll BigMod(ll a, ll n)
{
	ll x = 1, y = a;

	while (n)
	{
		if (n & 1)
			x = (x * y) % mod;
		y = (y * y) % mod;
		n /= 2;
	}
	return x;
}
ll InverseMod(ll a, ll m)
{
	return BigMod(a, m);
}
ll SOD(ll X)
{
	ll sum = 1;
   ll rt = sqrt(X);
	for (ll i = 0; i < primes.size() && primes[i] <= rt; i++)
	{
		if ( X % primes[i] == 0 ) {
			ll cnt = 0;

			while ( X % primes[i] == 0 ) {
				cnt++;
				X /= primes[i];
			}
			ll tot_pow = cnt * m + 1; /* finding the total number of terms of prime[i] in n^m */
			/*Sum of n terms = a*(r^n-1)/(r-1). */
			ll lob = (BigMod(primes[i], tot_pow) - 1) % mod; //a*(r^n-1)
			ll hor = InverseMod(primes[i] - 1, mod - 2);         //(r-1)
			sum = (sum * (lob % mod * hor % mod) % mod) % mod;
		}
	}
	if ( X > 1 ) {
		if ( X == mod ) //if X == 1000000007
			sum = 1;
		else {
			ll tot_pow = m + 1; /* finding the total number of terms of X in n^m */
			//a*(r^n-1),a = primes[i],thats why we added 1 to tot_pow
			ll lob = (BigMod(X, tot_pow) - 1) % mod; 
			ll hor = InverseMod(X - 1, mod - 2);   //(r-1)
			sum = (sum * (lob % mod * hor % mod) % mod) % mod;
		}
	}
	return sum;
}
int main()
{
	sieve();
	ll t;

	scanf("%lld", &t);
	for (ll k = 1; k <= t; k++)
	{
		scanf("%lld%lld", &n, &m);
		ll ans = SOD(n);
		printf("Case %lld: %lld\n", k, ans % mod);
	}

}