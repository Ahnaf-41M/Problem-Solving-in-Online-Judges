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

void Solve(int tc)
{
	int P, L, Q;
	set<int> ans;

	cin >> P >> L;
	P -= L;

	for (int i = 1; i * i <= P; i++) {
		if (P % i == 0) {
			int d1 = i, d2 = P / i;
			if (d1 > L) ans.insert(d1);
			if (d1 != d2 && d2 > L) ans.insert(d2);
		}
	}
	cout << "Case " << tc << ": ";
	if (ans.empty()) cout << "impossible\n";
	else {
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}