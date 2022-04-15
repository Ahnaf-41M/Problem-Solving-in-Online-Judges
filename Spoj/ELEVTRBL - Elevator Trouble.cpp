#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dis[MX];
int f, s, g, u, d;

void bfs()
{
	queue<int> q;
	q.push(s);
	dis[s] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur + u <= f && dis[cur + u] == -1) {
			dis[cur + u] = dis[cur] + 1;
			q.push(cur + u);
		}
		if (cur - d >= 1 && dis[cur - d] == -1) {
			dis[cur - d] = dis[cur] + 1;
			q.push(cur - d);
		}
	}
}
void Solve(int tc)
{
	cin >> f >> s >> g >> u >> d;
	bfs();
	if (dis[g] == -1) cout << "use the stairs\n";
	else cout << dis[g] << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dis, -1, sizeof(dis));
	int T = 1;
	//cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}