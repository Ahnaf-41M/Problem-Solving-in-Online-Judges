#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> adj[1200];

int dis[1110];

bool is_prime(int n)
{
	for (int j = 2; j <= sqrt(n); j++)
		if (n % j == 0)
			return false;
	return true;
}
void initialize()
{
	vector<int> prime;
	for (int i = 2; i <= 1100; i++)
		if (is_prime(i))
			prime.pb(i);
	for (int i = 1; i <= 1100; i++)
	{
		for (int j = 0; j < prime.size(); j++)
		{
			if (i % prime[j] == 0 && prime[j] != i)
				adj[i].pb(prime[j] + i);
		}
	}
}
void bfs(int st)
{
	dis[st] = 0;

	queue<int> Q;
	Q.push(st);

	while (!Q.empty())
	{
		int tp = Q.front();
		Q.pop();

		for (int ch : adj[tp])
		{
			if (dis[ch] == -1)
			{
				Q.push(ch);
				dis[ch] = dis[tp] + 1;
			}
		}
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	initialize();
	int t; cin >> t;

	for (int k = 1; k <= t; k++)
	{
		memset(dis, -1, sizeof(dis));
		int st, ed; cin >> st >> ed;
		bfs(st);
		cout << "Case " << k << ": " << dis[ed] << endl;
	}

	return 0;
}