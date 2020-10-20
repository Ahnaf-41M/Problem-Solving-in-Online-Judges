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
#define pii pair<int,int>
#define inf INT_MAX

vector<pair<pii, int> > adj[mx];
int n, m, k, x, y;
int TIME[mx], dis[mx], par[mx];
bool vis[mx];

void Dijkstra(int nd)
{
    vis[nd] = true;
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Q.push({0, nd});
    dis[nd] = 0;
    par[nd] = nd;
    TIME[nd] = 1;

    while (!Q.empty())
    {
        int node = Q.top().second;
        int cost = Q.top().first;
        Q.pop();

        for (auto ch : adj[node])
        {
            nd = ch.first.first;
            int hour = ch.first.second;
            int money = ch.second;

            if (dis[nd] > dis[node] + hour * k + money+(TIME[node]-1)*k)
            {
                par[nd] = node;
                
                dis[nd] = dis[node] + hour * k + money+(TIME[node]-1)*k;
                TIME[nd] = TIME[node] + 1;
                Q.push({dis[nd], nd});
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
    map<pii, int> mp;
    bool wrng = false;
    cin >> k >> n >> m;
    for (int i = 1; i <= n; i++) dis[i] = inf;
    W(m)
    {
        int hour, cost;
        cin >> x >> y >> hour >> cost;
        adj[x].pb({{y, hour}, cost});
        adj[y].pb({{x, hour}, cost});
        if (mp[ {x, y}])
            wrng = true;
        else
            mp[ {x, y}]++;
    }
    cin >> x >> y;
    Dijkstra(x);
    if (dis[y] == inf||wrng)
        cout << "Error";
    else
    {
        vector<int> ans;
        int v = y;
        ans.pb(v);

        while (par[v] != v)
        {
            v = par[v];
            ans.pb(v);
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i];
            if (i)
                cout << "->";
        }
        cout << " " << TIME[y] << " " << dis[y];
    }

    return 0;
}