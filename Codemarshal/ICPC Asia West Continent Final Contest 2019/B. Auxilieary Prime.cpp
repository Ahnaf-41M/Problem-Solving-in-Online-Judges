#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   10000005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)
#define  irep(i,a,b)     for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

bool mark[MX + 5];

void sieve()
{
	for (int i = 3; i <= MX; i += 2)
		mark[i] = true;
	for (int i = 3; i * i <= MX; i += 2)
		if (mark[i])
			for (int j = i * i; j <= MX; j += i)
				mark[j] = false;
	mark[2] = true;
}
void Solve()
{
	string s;
	bool ok = false;
	cin >> s;

	rep(i, 0, s.size() - 1) {
		string tmp = s;
		for (char ch = '0'; ch <= '9'; ch++) {
			if (i == 0 && ch == '0')
				continue;

			tmp[i] = ch;
			int n = stoi(tmp);
			if (mark[n]) {
				ok = true;
				break;
			}
		}
		if (ok)
			break;
	}
	if (ok)
		cout << "yes\n";
	else
		cout << "no\n";
	return;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	sieve();
	int t;
	cin >> t;

	W(t) {
		Solve();
	}
	// return 0;
}