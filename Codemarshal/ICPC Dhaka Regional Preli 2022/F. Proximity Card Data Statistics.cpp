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

vector<string> v = {"A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-"};

void Solve(int tc)
{
	map<string, set<string> > mp1, mp2, mp3;
	map<string, string> mp4, mp5, mp6;
	map<string, int> ans1, ans2;

	set<int> s1, s2;
	set<string> ID, YEAR;

	int n; cin >> n;
	cin.ignore(2000, '\n');
	while (n--) {
		string s;
		getline(cin, s);

		string id = s.substr(20, 13);
		int len = s.size(), i = len - 1;
		string bg, dob;

		string tStmp = s.substr(6, 4) + "/" + s.substr(3, 2) + "/" + s.substr(0, 2) + s.substr(10, 9);

		// cout << tStmp << "\n";

		for ( i = len - 1; i >= 0; i--) {
			if (s[i] == ' ') break;
			bg.pb(s[i]);
		}
		reverse(bg.begin(), bg.end());
		// cout << bg << "\n";
		// cout << tmp << "\n";

		i--;
		for (;; i--) {
			if (dob.size() == 4) break;
			dob.pb(s[i]);
		}
		reverse(dob.begin(), dob.end());
		// cout << dob << "\n";

		// mp1[bg].insert(id);
		// mp2[dob].insert(id);

		if (ID.find(id) == ID.end()) {
			ID.insert(id);
			mp4[id] = tStmp;
			mp5[id] = dob;
			mp6[id] = bg;
		}
		else {
			if (mp4[id] < tStmp) {
				mp4[id] = tStmp;
				mp5[id] = dob;
				mp6[id] = bg;
			}
		}
	}
	for (auto it : ID) {
		// cout << it << '\n';
		ans1[mp6[it]]++;
		ans2[mp5[it]]++;
	}

	for (auto it : v) {
		cout << it << " " << ans1[it] << "\n";
	}
	for (auto it : ans2) {
		cout << it.ff << " " << it.ss << "\n";
	}
}
signed main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

}