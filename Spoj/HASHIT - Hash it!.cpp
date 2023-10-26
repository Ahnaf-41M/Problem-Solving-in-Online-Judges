#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         100005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

string ans[101];
int mod = 101;

int generateHash(string s)
{
	int res = 0;
	for (int i = 0; i < s.size(); i++)
		res += (i + 1) * s[i];
	res = (res * 19) % mod;
	return res;
}
bool Add(string s)
{
	int hash = generateHash(s);

	// if it is already inserted before
	for (int j = 0; j < 20; j++) {
		int new_hash = (hash + (j * j) + (23 * j)) % mod;
		if (ans[new_hash] == s) {
			return false;
		}
	}

	// if it is not inserted before
	for (int j = 0; j < 20; j++) {
		int new_hash = (hash + (j * j) + (23 * j)) % mod;
		if (ans[new_hash] == "") {
			ans[new_hash] = s;
			return true;
		}
	}
	return false;
}
bool Del(string s)
{
	int hash = generateHash(s);
	for (int j = 0; j < 20; j++) {
		int new_hash = (hash + (j * j) + (23 * j)) % mod;
		if (ans[new_hash] == s) {
			ans[new_hash] = "";
			return true;
		}
	}
	return false;
}
void Solve(int tc)
{
	int n, tot = 0;
	cin >> n;
	while (n--) {
		string s; cin >> s;
		if (s[0] == 'A') {
			if (Add(s.substr(4)))
				tot++;
		}
		else {
			if (Del(s.substr(4)))
				tot--;
		}
	}
	cout << tot << "\n";
	for (int i = 0; i < 101; i++) {
		if (ans[i] != "")
			cout << i << ":" << ans[i] << "\n";
		ans[i] = "";
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

}