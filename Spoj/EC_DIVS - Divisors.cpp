#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           10005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int OK[MX], cnt[100005];
vector<int> adj[MX];
set<int> ans[100005], divs;
int n, till, mx;
multiset<int> nums;

void Sieve()
{
	OK[2] = 1;
	for (int i = 3; i < MX; i += 2)
		OK[i] = 1;
	for (int i = 3; i * i < MX; i += 2) {
		if (OK[i]) {
			for (int j = i * i; j < MX; j += i) {
				OK[j] = 0;
			}
		}
	}
	for (int i = 1; i < MX; i++) {
		if (OK[i]) continue;
		for (int j = i; j < MX; j += i) {
			adj[j].pb(i);
		}
	}
}
void Reset()
{
	for (int x : nums)
		for (int d : adj[x])
			cnt[d] = 0;
	for (int i = 1; i <= mx; i++) {
		ans[i].clear();
	}

	nums.clear();
	divs.clear();
}
void Solve(int tc)
{
	till = 0, mx = 0;

	cin >> n;
	while (n--) {
		string type;
		cin >> type;
		mx = max(mx, till);
		if (type == "UPD") {
			string op;
			int x;
			cin >> op >> x;

			if (op == "ADD") {
				till++;
				nums.insert(x);
				for (int d : adj[x]) {
					if (ans[cnt[d]].find(d) != ans[cnt[d]].end())
						ans[cnt[d]].erase(d);
					cnt[d]++;
					ans[cnt[d]].insert(d);
				}
			}
			else {
				till--;
				nums.erase(nums.find(x));
				for (int d : adj[x]) {
					ans[cnt[d]].erase(d);
					cnt[d]--;
					ans[cnt[d]].insert(d);
				}
			}
		}
		else {
			if (!till) cout << "-1";
			else for (int d : ans[till]) cout << d << " ";
			cout << "\n";
		}
	}

	Reset();

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