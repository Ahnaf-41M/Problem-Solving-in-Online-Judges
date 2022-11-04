#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int trie[MX][26], nxt, dp[MX];
int cnt[MX];

void Insert(string s)
{
	int root = 0;
	for (char ch : s) {
		int val = ch - 'a';
		if (trie[root][val] == 0)
			trie[root][val] = ++nxt;
		root = trie[root][val];
		cnt[root]++;
	}
}
void Clear()
{
	memset(dp, -1, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	memset(trie, 0, sizeof(trie));
	nxt = 0;
}
void dfs(int cur, int len)
{
	int res = 0;
	for (int i = 0; i < 26; i++) {
		if (trie[cur][i] == 0) continue;
		res = max(res, cnt[trie[cur][i]]);
		dfs(trie[cur][i], len + 1);
	}
	dp[len] = max(dp[len], res);
}
void Solve(int tc)
{
	Clear();
	int n, q;
	cin >> n >> q;

	while (n--) {
		string s;
		cin >> s;
		reverse(all(s));
		Insert(s);
	}
	dfs(0, 1);
	while (q--) {
		int x; cin >> x;
		cout << dp[x]  << "\n";
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