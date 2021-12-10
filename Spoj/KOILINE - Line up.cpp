#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           100005
#define  pi           2*acos(0.0)
#define  endl         "\n"
#define  int          long long
#define  mod          1000000007
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
#define  IOS          ios_base::sync_with_stdio(0);cin.tie(0);
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main()
{
	/*#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	   freopen("error.txt", "w", stderr);
	#endif*/
	IOS
	int n;
	ordered_set<int> s;

	cin >> n;

	int ar[n], ans[n];
	rep(i, 1, n) {
		int x; cin >> x;
		s.insert(x);
	}

	for (int &x : ar) cin >> x;
	irep(i, n - 1, 0) {
		auto it = s.find_by_order(ar[i]);
		ans[i] = *it;
		s.erase(it);
	}
	for (int x : ans) cout << x << "\n";

	//cerr << "Time: " << double(clock()) / (double) CLOCKS_PER_SEC;
}
