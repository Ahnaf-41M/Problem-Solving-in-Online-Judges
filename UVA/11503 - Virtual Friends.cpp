#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 100100


int par[mx], n;

int find(int a)
{
	if (par[a] < 0)
		return a;
	else
		return par[a] = find(par[a]);
}

void Union(int x, int y)
{
	int a = find(x);
	int b = find(y);

	if (a == b)
	{
		cout << abs(par[a]) << endl;
		return;
	}
	par[a] += par[b];
	par[b] = a;
	cout << abs(par[a]) << endl;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;

	W(t)
	{
		cin >> n;

		int ind = 1;
		map<string, int> name;
		string s1, s2;

		for (int i = 1; i <= n; i++)
			par[i] = -1;

		W(n)
		{
			cin >> s1 >> s2;
			if (!name[s1]) name[s1] = ind++;
			if (!name[s2]) name[s2] = ind++;
			Union(name[s1], name[s2]);
		}
	}

	return 0;
}