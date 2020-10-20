/*Consider the prime factorization of a number:- N = p^a * q^b* r^c ...
Now, the total divisors is given by (a+1)*(b+1)*(c+1)...
The number of prime divisors is let's say k.
Then Non-prime divisors is (Total - Prime divisors).*/
#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      1000005
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

bool prime[MX + 5];
vector<int> v;
void sieve()
{
	prime[2] = true;

	for (int i = 3; i <= MX; i += 2)
		prime[i] = true;

	v.pb(2);
	for (int i = 3; i <= MX; i += 2) {
		if (prime[i]) {
			v.pb(i);
			for (int j = i * 2; j <= MX; j += i) {
				prime[j] = false;
			}
		}
	}
}
int main()
{
	IOS
	sieve();

	ll t, n, i;

	cin >> t;

	W(t)
	{
		cin >> n;
		if (n == 1) cout << n << endl;
		else
		{
			ll ans = 1, prime_div = 0;

			for (ll i = 0; i < v.size() && v[i]*v[i] <= n; i++)
			{
				ll cnt_div = 0;
				while (n % v[i] == 0) {
					n /= v[i];
					cnt_div++;
				}
				if (cnt_div > 0)
					prime_div++;
				ans *= (cnt_div + 1);
			}
			if (n > 1) {
				ans *= 2;
				ans -= 1;
			}
			cout << ans - prime_div << endl;
		}
	}
}