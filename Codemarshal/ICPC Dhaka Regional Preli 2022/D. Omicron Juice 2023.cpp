#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           100005
#define  int          long long
#define  endl         "\n"
#define  PII          pair<int, int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

void Solve(int tc)
{
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	int mid = (a + b + c) / 3;
	cout << "Case " << tc << ": ";
	if (a == b && b == c) cout << "Peaceful\n";
	else if ((a + b + c) % 3) cout << "Fight\n";
	else if (abs(a - b) % k || abs(b - c) % k || abs(c - a) % k) cout << "Fight\n";
	else if ((a < k && b < k) || (b < k && c < k) || (c < k && a < k)) cout << "Fight\n";
	else if (abs(a - mid) % k || abs(b - mid) % k || abs(c - mid) % k) cout << "Fight\n";
	else cout << "Peaceful\n";

}
signed main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

}