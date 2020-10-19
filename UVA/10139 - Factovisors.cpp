#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 100005

bool is_prime[mx + 5];
int n, m;
vector<int> primes;

void sieve()
{
	int i, j;
	for (i = 3; i <= mx; i += 2)
		is_prime[i] = true;
	for (i = 3; i <= sqrt(mx); i += 2)
		if (is_prime[i])
			for (j = i + i; j <= mx; j += i)
				is_prime[j] = false;
	primes.pb(2);
	for (i = 3; i <= mx; i += 2)
		if (is_prime[i])
			primes.pb(i);
}
int get_power(int n, int p)
{
	int ans = 0;

	while (n)
	{
		n /= p;
		ans += n;
	}
	return ans;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve();

	while (cin >> n >> m)
	{
		int tm = m, tn = n;
		int i = 0;
		bool ok = true;

		if (n >= m)
			cout << m << " divides " << n << "!\n";

		else
		{
			while (primes[i]*primes[i] <= m)
			{
				int cnt = 0;
				while (tm % primes[i] == 0)
				{
					tm /= primes[i];
					cnt++;
				}
				if (get_power(n, primes[i]) < cnt) {
					ok = false; break;
				}
				i++;
			}
			if(tm > 1 && ok)
			{
				int cnt=0;
				while(tn)
				{
					tn/=tm;
					cnt+=tn;
				}
				if(cnt < 1)
					ok = false;
			}
			
			if (ok)
				cout << m << " divides " << n << "!\n";
			else
				cout << m << " does not divide " << n << "!\n";
		}

	}

	return 0;
}