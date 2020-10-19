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

vector<int> adj[1000];
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, s, i, j;
	map<char, int> mp1;
	map<int, char> mp2;

	char ch;
	int k = 0;

	for (ch = 'A'; ch <= 'Z'; ch++)
		mp1[ch] = ++k;
	ch = 'A';
	for (i = 1; i <= 26; i++)
		mp2[i] = ch++;

	cin >> t;

	for (i = 1; i <= t; i++)
	{
		string s;
		stack<char> St;
		map<char, int> ans;
		bool ache[30] = {};

		cin >> s;

		for (j = 0; j < s.size(); j++)
		{
			if (St.empty())
				St.push(s[j]);
			else
			{
				if (St.top() == s[j])
					St.pop();
				else
				{
					adj[mp1[St.top()]].pb(mp1[s[j]]);
					adj[mp1[s[j]]].pb(mp1[St.top()]);
					ache[mp1[St.top()]] = true;
					ache[mp1[s[j]]] = true;
					St.push(s[j]);
				}
			}
		}
		for (j = 1; j <= 26; j++)
		{
			if (ache[j])
			{
				ans[mp2[j]] = adj[j].size();
			}
		}
		cout << "Case " << i << "\n";
		for (auto it : ans)
		{
			cout << (it.first) << " = " << (it.second) << endl;
		}
		for (j = 1; j <= 26; j++)
			adj[j].clear();

	}
}