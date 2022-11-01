#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int prime_pref[MX];
void Sieve()
{
	prime_pref[1] = prime_pref[2] = 1;
	for (int i = 3; i < MX; i += 2)
		prime_pref[i] = 1;
	for (int i = 3; i * i < MX; i += 2) {
		if (prime_pref[i]) {
			for (int j = i * i; j < MX; j += i) {
				prime_pref[j] = 0;
			}
		}
	}
	for (int i = 2; i < MX; i++) prime_pref[i] += prime_pref[i - 1];
}
void Solve(int tc)
{
	int n, k, ans = 0, tot_primes = 0;
	cin >> n >> k;

	tot_primes = prime_pref[n]; //total primes till n

	int ar[k];
	for (int &x : ar) {
		cin >> x;
		if (x <= n) tot_primes--;
	}

	for (int i = 1; i < (1 << k); i++) {
		int cur = 1, cnt = 0;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) {
				cur *= ar[j];
				cnt++;
			}
		}
		// cout << cur << " -- " << cnt << "\n";
		if (cnt & 1) ans += (n / cur);
		else ans -= (n / cur);
	}
	ans += tot_primes;
	cout << "Case " << tc << ": " << n - ans << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Sieve();
	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}