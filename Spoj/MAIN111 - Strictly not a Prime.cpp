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

bool Prime[MX];
int pre[MX];
void Sieve()
{
	Prime[2] = 1;
	for (int i = 3; i < MX; i += 2)
		Prime[i] = 1;
	for (int i = 3; i < MX; i++)
		if (Prime[i])
			for (int j = i * i; j < MX; j += i)
				Prime[j] = 0;
}
bool SubSeq(int n)
{
	vector<int> v;
	while (n) v.pb(n % 10), n /= 10;
	reverse(all(v));

	int sz = v.size();

	for (int i = 0; i < (1 << sz); i++) {
		int cur_num = 0;
		for (int j = 0; j < sz; j++) {
			if (i & (1 << j)) {
				cur_num = cur_num * 10 + v[j];
			}
		}
		if (Prime[cur_num]) return false;
	}
	return true;
}
void Solve(int tc)
{
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	cout << pre[b] - pre[a - 1] << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Sieve();
	rep(i, 1, MX - 1) pre[i] = pre[i - 1] + SubSeq(i);

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}