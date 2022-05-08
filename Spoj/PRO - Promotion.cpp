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
	int n, k, tot_cst = 0;
	multiset<int> S;

	cin >> n;
	while (n--) {
		cin >> k;
		while (k--) {
			int x; cin >> x;
			S.insert(x);
		}
		if (S.size() > 1) {
			auto it1 = S.begin();
			auto it2 = S.end(); it2--;
			tot_cst += (*it2) - (*it1);
			S.erase(it1), S.erase(it2);
		}
	}

	cout << tot_cst << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	//cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}