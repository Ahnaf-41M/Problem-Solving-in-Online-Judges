#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
#define  all(v)          v.begin(),v.end()
#define  ZERO(a)         memset(a,0,sizeof(a))
#define  MINUS(a)        memset(a,-1,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

vector<int> mx_window_of_len_d(int a[], int n, int d)
{
	vector<int> ans;
	deque<int> Q;
	int i;

	rep(i, 0, d) {
		while (!Q.empty() && a[i] > a[Q.back()])
			Q.pop_back();
		Q.pb(i);
	}

	rep(i, d, n) {

		ans.pb(a[Q.front()]);

		while (!Q.empty() && Q.front() <= (i - d))
			Q.pop_front();
		while (!Q.empty() && a[i] > a[Q.back()])
			Q.pop_back();

		Q.push_back(i);
	}
	ans.pb(a[Q.front()]);
	return ans;
}
vector<int> mn_window_of_len_d(int a[], int n, int d)
{
	vector<int> ans;
	deque<int> Q;
	int i;

	rep(i, 0, d) {
		while (!Q.empty() && a[i] < a[Q.back()])
			Q.pop_back();
		Q.pb(i);
	}

	rep(i, d, n) {

		ans.pb(a[Q.front()]);

		while (!Q.empty() && Q.front() <= (i - d))
			Q.pop_front();
		while (!Q.empty() && a[i] < a[Q.back()])
			Q.pop_back();

		Q.push_back(i);
	}
	ans.pb(a[Q.front()]);
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

	// IOS
	int t, i, j, k;

	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		int n, d;
		scanf("%d%d", &n, &d);
		int a[n];
		rep(i, 0, n) scanf("%d", &a[i]);

		vector<int> mxV, mnV;
		mxV = mx_window_of_len_d(a, n, d);
		mnV = mn_window_of_len_d(a, n, d);
		int ans = 0;

		rep(i, 0, mxV.size()) {
			// cout << mnV[i] << " " << mxV[i] << endl;
			ans = max(ans, mxV[i] - mnV[i]);
		}

		printf("Case %d: %d\n", k, ans);
	}
}