#include <bits/stdc++.h>
#define mx 100005
using namespace std;
//#define pb push_back

vector<int> adj[mx],ans;
stack<int> S;
int disc[mx], low[mx],out_deg[mx];
bool vis[mx];
int Timer;

void tarjanSCC(int nd)
{
    disc[nd] = low[nd] = ++Timer;
    S.push(nd);
    vis[nd] = true;

    for (auto v : adj[nd])
    {
        if (!disc[v]) //check disc
        {
            tarjanSCC(v);
            low[nd] = min(low[nd], low[v]);
        }
        else if (vis[v]) //check vis
            low[nd] = min(low[nd], disc[v]);
    }

    if (low[nd] == disc[nd])
    {
        vector<int> tmp;
        while (true)
        {
            int tp = S.top();
            S.pop();
            tmp.push_back(tp);
            vis[tp] = false; //switch vis
            if (nd == tp)
                break;
        }
        if(tmp.size()==1)
          ans.push_back(tmp[0]);
    }
}
int main()
{
    int n, m;
    int t;
    cin>>t;

    for(int k = 1; k <= t; k++)
    {
        cin>>n>>m;
        int cnt=0;
        while(m--)
        {
            int x, y;
            cin >> x >> y;
            if(x!=y)
            {
                adj[x].push_back(y);
                out_deg[x]++;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!disc[i])
                tarjanSCC(i);
        for(int i = 1; i < ans.size(); i++)
        {
             if(out_deg[ans[i]])
               cnt++;
        }
        cout<<"Case "<<k<<": "<<cnt<<endl;
        for(int i = 1; i <= n; i++)
        {
             vis[i] = 0;
             adj[i].clear();
             out_deg[i] = 0;
             low[i] = 0;
             disc[i] = 0;
        }
        ans.clear();

    }


}
