#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int pref[MX];
void Sieve()
{
	for (int i = 3; i < MX; i += 2) pref[i] = 1;
	for (int i = 3; i < MX; i += 2)
		if (pref[i])
			for (int j = i * i; j < MX; j += i)
				pref[j] = 0;
	pref[2] = 1;
	for (int i = 3; i < MX; i++) pref[i] += pref[i - 1];

}

void Solve(int tc)
{
	int n, k, ans = 0;
	cin >> n >> k;

	if (!k) ans = n * (n + 1) / 2 - n;
	else {
		int i = 2, j = 2;

		while (i <= n) {
			while (i <= n && pref[i] - pref[j - 1] < k) i++;
			while (j <= i && pref[i] - pref[j - 1] >= k) ans += (n - i + 1), j++;
			i++;
		}
	}
	cout << ans << "\n";
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
