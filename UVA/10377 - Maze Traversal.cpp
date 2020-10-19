#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define w(t) while(t--)

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char pos[] = {'N', 'E', 'S', 'W'};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d ", &t);

	w(t)
	{
		int r, c, i, j, x, y;
		cin >> r >> c;
		
		char s[r + 3][c + 3];
		memset(s,'*',sizeof(s));

		for (i = 1; i <= r; i++)
		{
			getchar();
			for (j = 1; j <= c; j++)
			{
				scanf("%c",&s[i][j]);
			}
		}
		cin >> x >> y;
		bool ok = true;
		int dir = 0;
		string ss;

		while (ok)
		{
			getline(cin, ss);

			for (i = 0; i < ss.size(); i++)
			{
				if (ss[i] == 'F' && s[x + dx[dir]][y + dy[dir]] == ' ')
				{
					x += dx[dir]; y += dy[dir];
				}
				else if (ss[i] == 'R')
				{
					dir++; dir %= 4;
				}
				else if (ss[i] == 'L')
				{
					dir--;
					if (dir < 0)
						dir = 3;
				}
				else if (ss[i] == 'Q')
				{
					ok = false;
					break;
				}
			}
			if (!ok)
				break;
		}
		cout << x << " " << y << " " << pos[dir] << endl;
		if (t)
			cout << endl;

	}
}