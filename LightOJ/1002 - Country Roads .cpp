#include<bits/stdc++.h>

#define endl "\n"
#define pb   push_back
#define ll   long long
#define ff first
#define ss second

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;

struct Graph
{
	int x, y, wt;
};

Graph adj[16005];
bool vis[505];
int n, m,par[505],dis[505];
vector<pair<int,int> > MST[505];

bool cmp(Graph a,Graph b)
{
	return a.wt < b.wt;
}
int root(int v)
{
	if(par[v] < 0) return v;
	else return par[v] = root(par[v]);
}
void Union(int x,int y)
{
	par[x] = y;
}
void Kruskals()
{
	int i,j;
	rep(i,0,m)
	{
		int a = adj[i].x;
		int b = adj[i].y;
		int w = adj[i].wt;

		int r1 = root(a);
		int r2 = root(b);

		if(r1!=r2)
		{
			Union(r1,r2);
			MST[a].pb({b,w});
			MST[b].pb({a,w});
		}
	}
}
void dfs(int nd,int w)
{
	vis[nd] = true;
	dis[nd] = w;

	for(auto ch : MST[nd]){
		if(!vis[ch.ff]){
			dfs(ch.ff,max(w,ch.ss));
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, i, j, n, k;
	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		int home;
		scanf("%d%d", &n, &m);
		rep(i,0,n){
			par[i] = -1;
			dis[i] = -1;
		}
		rep(i, 0, m) {
			cin >> adj[i].x >> adj[i].y >> adj[i].wt;
		}
		cin>>home;

		sort(adj,adj+m,cmp);
		Kruskals();
		dfs(home,0);

		printf("Case %d:\n",k);
		rep(i,0,n){
			if(dis[i]==-1){
				printf("Impossible\n");
			}
			else{
				printf("%d\n",dis[i]);
			}
		}
		rep(i,0,m){
			adj[i].x = 0;adj[i].y = 0;adj[i].wt = 0;
		}
		rep(i,0,n){
			MST[i].clear();
			vis[i] = false;
			dis[i] = -1; par[i] = -1;
		}
	}

	return 0;
}