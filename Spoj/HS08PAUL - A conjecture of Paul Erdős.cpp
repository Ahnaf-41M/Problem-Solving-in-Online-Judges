#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           10000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

bool ok[MX];
int pre[MX];

void Sieve()
{
	ok[2] = 1;
	for (int i = 3; i < MX; i += 2) ok[i] = 1;
	for (int i = 3; i < MX; i += 2)
		if (ok[i])
			for (int j = i * i; j < MX; j += i)
				ok[j] = 0;
}
void Work()
{
	for (int x = 1; x <= 10000; x++) {
		for (int y = 1; y <= 100; y++) {
			int cur = x * x + (y * y * y * y);
			if (cur < MX && ok[cur]) pre[cur] = 1;
		}
	}
	for (int i = 2; i < MX; i++) pre[i] += pre[i - 1];
}
void Solve(int tc)
{
	int n;
	cin >> n;
	cout << pre[n] << "\n";
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