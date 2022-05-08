#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           100005
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
#define  IOS          ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;

void Solve(int tc)
{
	int q, x;
	char ch;
	ordered_set<int> S;

	cin >> q;

	while (q--) {
		cin >> ch >> x;
		if (ch == 'I') S.insert(x);
		else if (ch == 'D' && S.find(x) != S.end()) S.erase(x);
		else if (ch == 'K') {
			if (x > (int)S.size()) cout << "invalid\n";
			else cout << *S.find_by_order(x - 1) << "\n";
		}
		else if (ch == 'C') cout << S.order_of_key(x) << "\n";
	}
}
int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif
	IOS

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

}