#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 100005
vector<int> adj[mx], ans;
int indeg[mx];
bool cycle;
int  n, m, color[mx];

void kahns(int n)
{
	int i,j;
	priority_queue<int,vector<int>, greater<ll> > pq;

	for(i = 1; i <= n; i++) 
		if(indeg[i]==0)
			pq.push(i);
	
	while(!pq.empty())
	{
		int fr = pq.top();
		pq.pop();
		ans.pb(fr);

		for(int ch : adj[fr])
		{
			indeg[ch]--;
			if(indeg[ch]==0)
				pq.push(ch);		
		}
	}
	if(ans.size()==n)
		rep(i,ans.size()) cout<<ans[i]<<" ";
	else
		cout<<"Sandro fails.\n";
	
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	int i;

	W(m)
	{
		int x, y, i;
		cin >> x >> y;
		adj[x].pb(y);
		indeg[y]++;
	}
	kahns(n);

	return 0;
}