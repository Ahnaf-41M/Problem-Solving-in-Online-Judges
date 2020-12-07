#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)        for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 100000

vector<int> adj[mx];
int cost[mx], a, b;
vector<int> primes;
bool arr[mx];

void bfs(int nd)
{
	cost[nd] = 0;
	queue<int> Q; Q.push(nd);

	while (!Q.empty())
	{
		int fr = Q.front(); Q.pop();
		if (fr == b)
			break;
		for (int ch : adj[fr])
		{
			if (cost[ch] == -1)
			{
				Q.push(ch);
				cost[ch] = 1 + cost[fr];
			}
		}
	}
}
bool is_valid(int x, int y)
{
	int dif = 0;
	while (x)
	{
		if (x % 10 != y % 10)
			dif++;
		x /= 10; y /= 10;
	}
	return dif == 1;
}
void make_ADJ()
{
	int i, j, x, y;

	for (i = 0; i < primes.size(); i++)
	{
		for (j = i + 1; j < primes.size(); j++)
		{
			x = primes[i]; y = primes[j];

			if (is_valid(x, y))
			{
				adj[x].pb(y);
				adj[y].pb(x);
			}
		}
	}
}
bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
void sieve()
{
	for (int i = 1001; i <= 10000; i++)
		if (is_prime(i))
			primes.pb(i);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(cost, -1, sizeof(cost));
	sieve();
	make_ADJ();
	//cout << primes.size();
	int t; cin >> t;

	W(t)
	{
		cin >> a >> b;
		bfs(a);
		if (cost[b] == -1)
			cout << "Impossible\n";
		else
			cout << cost[b] << endl;
		for (int i = 1000; i <= 9999; i++)
			cost[i] = -1;

	}
	return 0;
}