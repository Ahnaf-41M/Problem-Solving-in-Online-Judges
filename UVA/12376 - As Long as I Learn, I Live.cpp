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

vector<int> adj[100005];
int a[10005];
bool vis[10005] = {};
int ans, node;

void BFS(int nd)
{
    vis[nd] = 1;
    queue<int> Q;

    Q.push(nd);

    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        int mx = 0, pos = 0;

        for (auto idx : adj[p])
        {
            if (a[idx] > mx || a[idx] == mx && adj[idx] > adj[mx])
            {
                mx = a[idx];
                pos = idx;
            }
        }
        if (pos != 0)
        {
            Q.push(pos);
            ans += mx;
            node = pos;
        }
        else
            break;
    }
}
int main()
{
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, m, k = 1, i, j;

    cin >> t;

    for (k = 1; k <= t; k++)
    {

        cin >> n >> m;
        ans = 0, node = 0;

        for (i = 0; i < n; i++)
            cin >> a[i];

        W(m)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }
        BFS(0);

        cout << "Case " << k << ": " << ans << " " << node << endl;

        for (i = 0; i < n; i++)
        {
            a[i] = 0;
            vis[i] = 0;
            adj[i].clear();
        }


    }

    return 0;
}

