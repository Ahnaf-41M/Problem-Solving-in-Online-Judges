#include<bits/stdc++.h>
using namespace std;

#define ll long long

set<int> St;
vector<char> s[100005];
map<pair<int, int>, int> mp;
int loop, n, m, steps;

void call(int x, int y)
{
	if ((x >= 0 && y >= 0) && (x < n && y < m))
	{
		if (!mp[ {x, y}])
		{
			steps++;
			St.insert(steps);
			mp[ {x, y}] = steps;
			if (s[x][y] == 'N')
				call(x - 1, y);
			else if (s[x][y] == 'S')
				call(x + 1, y);
			else if (s[x][y] == 'E')
				call(x, y + 1);
			else
				call(x, y - 1);
		}
		else if (!loop)
		{
			loop = mp[ {x, y}];
			return;
		}

	}
	else
		return;
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int k, i, j;

	while (cin >> n >> m >> k && n && m && k)
	{
		char ch;
		steps = 0;

		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin >> ch, s[i].push_back(ch);
		call(0, k - 1);
		if (!loop)
		{
			cout << St.size() << " step(s) to exit\n";
			St.clear();
			mp.clear();
			loop = 0;
		}
		else
		{
			cout << loop - 1 << " step(s) before a loop of " << St.size() - loop + 1 << " step(s)\n";
			St.clear();
			mp.clear();
			loop = 0;
		}
		for (i = 0; i < n; i++)
			s[i].clear();
	}
}
