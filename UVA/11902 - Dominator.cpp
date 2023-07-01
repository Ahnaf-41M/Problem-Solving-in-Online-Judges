#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         105
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int graph[MX][MX], n, curNode;
vector<int> adj[MX];
int vis1[MX], vis2[MX];
char ans[MX][MX];

void dfs1(int nd)
{
	vis1[nd] = 1;
	for (int ch : adj[nd])
		if (!vis1[ch])
			dfs1(ch);
}
void dfs2(int nd)
{
	if (nd == curNode) return;
	vis2[nd] = 1;

	for (int ch : adj[nd])
		if (!vis2[ch])
			dfs2(ch);
}
void printLine()
{
	cout << "+";
	for (int i = 1; i <= 2 * n - 1; i++) cout << "-";
	cout << "+\n";
}
void Clear()
{
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		vis1[i] = 0;
		for (int j = 0; j < n; j++) {
			ans[i][j] = 'N';
		}
	}
}
void Solve(int tc)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				adj[i].pb(j);
		}
	}

	dfs1(0);
	// for (int j = 0; j < n; j++) ans[0][j] = 'Y';
	for (int i = 0; i < n; i++) {
		curNode = i;
		dfs2(0);
		for (int j = 0; j < n; j++) {
			if (vis1[j] && !vis2[j]) ans[i][j] = 'Y';
			else ans[i][j] = 'N';
			vis2[j] = 0;
		}

	}

	cout << "Case " << tc << ":\n";
	printLine();
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << "|";
		}
		cout << "\n";
		printLine();
	}

	Clear();
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

}