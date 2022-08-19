#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int nxt[MX], cnt[MX];
int n;
void Sieve()
{
	nxt[2] = 2;
	for (int i = 2; i < MX; i++)
		nxt[i] = i;
	for (int i = 2; i < MX; i++) {
		if (nxt[i] == i) {
			for (int j = i * i; j < MX; j += i) {
				if (nxt[j] == j)
					nxt[j] = i;
			}
		}
	}
}
bool cmp(int x, int y)
{
	if (cnt[x] > cnt[y]) return true;
	if (cnt[x] == cnt[y]) return x < y;
	return false;
}
void Solve(int tc)
{
	int zero = 0, one = 0;

	cin >> n;

	vector<int> ar(n), primes;
	rep(i, 0, n - 1) {
		cin >> ar[i];
		zero += (!ar[i]), one += (ar[i] == 1);
		int x = ar[i];
		while (nxt[x] > 1) {
			int d = nxt[x];
			if (!cnt[d]) primes.pb(d);
			cnt[d]++;
			while (x % d == 0) x /= d;
		}
	}
	if (primes.empty()) {
		if (one) cout << one << "\n";
		else cout << 2 << "\n";
		return;
	}
	sort(all(primes), cmp);

	int r1 = 0, r2 = 0, r3 = 0;
	for (int x : ar) {
		r1 += (x % 2);
		r2 += min(x % primes[0], primes[0] - (x % primes[0]));
		r3 += min(x % 3, 3 - (x % 3));
	}
	cout << min({r1, r2, r3}) << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Sieve();
	int T = 1;
	//cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}