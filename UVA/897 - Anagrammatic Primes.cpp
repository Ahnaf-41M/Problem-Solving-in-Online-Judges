#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 20000000

vector<int> Ana_primes;
bool is_prime[mx + 5];

void sieve()
{
	int i, j;
	is_prime[2] = true;

	for (i = 3; i <= mx; i += 2)
		is_prime[i] = true;
	for (i = 3; i <= sqrt(mx); i += 2)
		if (is_prime[i])
			for (j = i + i; j <= mx; j += i)
				is_prime[j] = false;

	Ana_primes.pb(2);
	for (i = 3; i <= mx; i += 2)
		if (is_prime[i])
			Ana_primes.pb(i);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve();

	int n;
	while (cin >> n, n)
	{
		int up = upper_bound(Ana_primes.begin(), Ana_primes.end(), n) - Ana_primes.begin();
		int ans = 0;
		int range = n, _tens = 1;

		while (range)
		{
			range /= 10;
			_tens *= 10;
		}

		for (int i = up; i < Ana_primes.size(); i++)
		{
			if (_tens > Ana_primes[i])
			{
				bool ok = true;
				string s = to_string(Ana_primes[i]);
				sort(s.begin(), s.end());

				do
				{
					int x = stoi(s);
					if (!is_prime[x])
					{
						ok = false;
						break;
					}
				} while (next_permutation(s.begin(), s.end()));
				
				if (ok)
					ans = Ana_primes[i];
			}
			else
				break;
			if (ans)
				break;

		}
		if (ans)
			cout << ans << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}