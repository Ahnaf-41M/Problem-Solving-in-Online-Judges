#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vector<vi> adj;
int dfs_num[107], low[107], artiVertex[107], parent[107];
int timer, dfsRoot, rootChildren;

void DFS(int u)
{
    low[u] = dfs_num[u] = timer++;
    for (int v : adj[u])
    {
        if (dfs_num[v] == -1)
        {
            parent[v] = u;
            if (u == dfsRoot)
                rootChildren++;
            DFS(v);

            if (low[v] >= dfs_num[u])
                artiVertex[u] = 1;
            low[u] = min(low[u], low[v]);
        }
        else if (v != parent[u])
            low[u] = min(low[u], dfs_num[v]);

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    while (cin>>n,n)
    {   
        string line;
        adj.assign(105, vi(0));
        int v, next;

        cin.ignore();
        while (getline(cin,line))
        {
            stringstream ss(line);
            if (line == "0")
                break;
            ss >> v;
            while (ss >> next)
            {
                adj[v].push_back(next);
                adj[next].push_back(v);
            }
        }

        memset(dfs_num,-1,sizeof(dfs_num));
        memset(low,0,sizeof(low));
        memset(parent,0,sizeof(parent));
        memset(artiVertex,0,sizeof(artiVertex));
        timer = 0;

        for (int i = 1; i <= n; i++)
        {
            if (dfs_num[i] == -1)
            {
                dfsRoot = i;
                rootChildren = 0;
                DFS(i);
                if(rootChildren > 1)
                    artiVertex[i] = 1;
                else
                    artiVertex[i] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += artiVertex[i];
        cout << ans << endl;
    }

    return 0;
}
