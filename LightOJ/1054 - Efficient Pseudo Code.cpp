#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

bool OK[MX];
vector<int> v;
int mod = 1e9 + 7;
void Sieve()
{
	for (int i = 3; i < MX; i += 2)
		OK[i] = 1;
	for (int i = 3; i * i < MX; i += 2)
		if (OK[i])
			for (int j = i * i; j < MX; j += i)
				OK[j] = 0;
	v.pb(2);
	for (int i = 3; i < MX; i += 2)
		if (OK[i])
			v.pb(i);
}
int BigMod(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return res;
}
int Inverse_Mod(int a, int p)
{
	return BigMod(a, p);
}
int SOD(int n, int m)
{
	int ans = 1;
	for (int x : v) {
		if (x * x > n) break;
		if (n % x == 0) {
			int POW = 0;
			while (n % x == 0)
				POW++, n /= x;
			POW = POW * m + 1;

			/* finding the total number of terms of x in n^m */
			/* Sum of n terms = a*(r^n-1)/(r-1). Here, r = x.*/

			int lob = (BigMod(x, POW) - 1) % mod; //a*(r^n-1)
			int hor = Inverse_Mod(x - 1, mod - 2) % mod; // 1/(r-1)
			ans = (ans * ((lob * hor) % mod)) % mod;
		}
	}
	if (n > 1) {
		if (n == mod) ans = 1; //if n == 1000000007
		else {
			int POW = m + 1;
			int lob = (BigMod(n, POW) - 1) % mod; // a*(r^n-1)
			int hor = Inverse_Mod(n - 1, mod - 2) % mod; // 1/(r-1)
			ans = (ans * ((lob * hor) % mod)) % mod;
		}
	}
	return ans;
}
void Solve(int tc)
{
	/*Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * (1 + p2 + p2^2 ... p2^a2) *.................
	  ....................*(1 + pk + pk^2 ... pk^ak) */
	int n, m;
	cin >> n >> m;
	cout << "Case " << tc << ": " << SOD(n, m) << "\n";
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