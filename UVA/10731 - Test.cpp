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
#define VC vector<char>

vector<int> adj[mx];
int n, low[mx], disc[mx], timer = 0;
bool vis[mx];
map<int, char> name;
stack<int> S;
priority_queue<VC, vector<VC>, greater<VC> > pq;

void tarjan(int nd)
{
    vis[nd] = true;
    disc[nd] = low[nd] = ++timer;
    S.push(nd);
    for (int ch : adj[nd])
    {
        if (!disc[ch])
        {
            tarjan(ch);
            low[nd] = min(low[nd], low[ch]);
        }
        else if (vis[ch])
            low[nd] = min(low[nd], disc[ch]);
    }
    if (low[nd] == disc[nd])
    {
        VC tmp;
        while (true)
        {
            int tp = S.top();
            S.pop();
            tmp.pb(name[tp]);
            vis[tp] = false;
            if (tp == nd)
                break;
        }
        sort(tmp.begin(), tmp.end());
        pq.push(tmp);
    }
}
void CLEAR(int ind)
{
    for (int i = 1; i <= ind; i++)
    {
        adj[i].clear();
        vis[i] = false;
        low[i] = disc[i] = 0;
    }
    name.clear();
    timer = 0;
    while (!S.empty())
        S.pop();
}
int main()
{
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 0;

    while (cin >> n, n)
    {
        char ch[10];
        int i, ind = 0, j;
        map<char, int> mp;
        if (t)
            cout << endl;
        t++;

        rep(i, n)
        {
            for (j = 1; j <= 6; j++)
            {
                cin >> ch[j];
                if (!mp[ch[j]])
                {
                    mp[ch[j]] = ++ind;
                    name[ind] = ch[j];
                }
            }
            for (j = 1; j <= 5; j++)
            {
                if (ch[j] != ch[6])
                    adj[mp[ch[6]]].pb(mp[ch[j]]);
            }
        }
        for (i =  1; i <= ind; i++)
            if (!disc[i])
                tarjan(i);
        while (!pq.empty())
        {
            auto ans = pq.top();
            pq.pop();
            rep(i, ans.size()) {
                cout << ans[i];
                if (i != ans.size() - 1) cout << " ";
            }
            cout << endl;
        }
        CLEAR(ind);
    }

    return 0;
}
