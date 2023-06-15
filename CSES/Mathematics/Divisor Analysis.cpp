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

int n;
int MOD = 1e9 + 7;

int BinExp(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		p >>= 1;
	}
	return res;
}
void Solve(int tc)
{
	int nod = 1, sod = 1, product = 1, odd_pow = 0, nod2 = 1;
	int number = 1, sq = 1;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, k;
		cin >> x >> k;

		// a^n ≡ a^(n % φ(MOD)) % MOD. Here MOD = 1e9+7, which is prime. Hence φ(MOD) = MOD-1.
		if ((k & 1) && odd_pow == 0) {
			odd_pow = 1;
			nod2 = nod2 * ((k + 1) / 2) % (MOD - 1);
		}
		else {
			nod2 = nod2 * (k + 1) % (MOD - 1);
		}
		sq = sq * BinExp(x, (k / 2)) % MOD;   // square of the number
		number = number * BinExp(x, k) % MOD; // the original number

		//number of divisors
		nod = nod * (k + 1) % MOD;

		//sum of divisors
		sod = sod * (BinExp(x, k + 1) - 1) % MOD * BinExp(x - 1, MOD - 2) % MOD;

	}

	//product of divisors
	if (!odd_pow)
		product = BinExp(sq, nod2) % MOD;     // the number is square number
	else
		product = BinExp(number, nod2) % MOD; // the number is not a square number

	cout << nod << " " << sod << " " << product << "\n";
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

}