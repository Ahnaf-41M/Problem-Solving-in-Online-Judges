#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define mx 100005

int par[mx], m, n, q;

int find(int a)
{
	if (par[a] == a)
		return a;
	else
		return par[a] = find(par[a]);
}
void Union(int a, int b)
{
	int a1 = find(a);
	int b1 = find(b);
	if (a1 > b1)
		par[b1] = a1;
	else
		par[a1] = b1;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	W(m)
	{
		int u, v; cin >> u >> v;
		Union(u, v);
	}
	cin >> q;
	W(q)
	{
		int x, y; cin >> x >> y;
		int p1 = find(x);
		int p2 = find(y);
		if (par[p1] == par[p2])
			cout << "TIE\n";
		else
		{
			if (par[p1] > par[p2])
				cout << x << endl;
			else
				cout << y << endl;
		}
	}

	return 0;
}