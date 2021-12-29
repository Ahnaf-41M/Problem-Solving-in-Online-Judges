#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           115
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

bool Prime[MX];
vector<int> v;
vector<PII> NOD;

void Sieve()
{
	Prime[2] = 1;
	for (int i = 3; i < MX; i += 2)
		Prime[i] = 1;
	for (int i = 3; i * i < MX; i += 2)
		if (Prime[i])
			for (int j = i * i; j < MX; j += i)
				Prime[j] = 0;
	v.pb(2);
	for (int i = 3; i < MX; i += 2)
		if (Prime[i])
			v.pb(i);
}
void Work()
{
	for (int n = 1; n < MX; n++) {
		int divs = 1;
		for (int d : v) {
			int cnt = 0, m = n;
			while (m)
				cnt += (m / d), m /= d;
			divs *= (cnt + 1);
		}
		NOD.pb({divs, n});
	}
}
void Solve(int tc)
{
	int n;
	cin >> n;

	PII p = {n, -1};
	int ind = lower_bound(all(NOD), p) - NOD.begin();

	if (ind == NOD.size() || NOD[ind].ff != n) cout << "nai\n";
	else cout << NOD[ind].ss << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Sieve();
	Work();

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}