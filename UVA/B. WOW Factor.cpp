#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(a,b,c)      for(int i = a; i < b; i+=c)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, _w = 0, _o = 0, ans = 0;

	string s;

	cin >> s;

	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == 'o')
			_o += _w;
		else if (i > 0 && s[i - 1] == 'v')
		{
			_w++;
			ans += _o;
		}
	}
	cout << ans << endl;

	return 0;
}