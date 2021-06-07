#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[5005][5005];
string s1, s2;
int n, m;

int call(int n, int m)
{
	if (n == 0) return m; //add the remaining characters of s2
	if (m == 0) return n; //remove the remaining characters of s1
	if (dp[n][m] != -1) return dp[n][m];

	if (s1[n - 1] == s2[m - 1])
		return dp[n][m] = call(n - 1, m - 1);
	else {
		int Add = 1 + call(n, m - 1); //add a character
		int Remove = 1 + call(n - 1, m); //remove a character
		int Replace = 1 + call(n - 1, m - 1); //replace a character

		return dp[n][m] = min(min(Add, Remove), Replace);
	}
}
void Solve(int tc)
{
	memset(dp, -1, sizeof(dp));
	cin >> s1 >> s2;
	n = s1.size(), m = s2.size();

	cout << call(n, m);
	return;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	//cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}