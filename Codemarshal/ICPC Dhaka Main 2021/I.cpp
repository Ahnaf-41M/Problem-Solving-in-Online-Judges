#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           10005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int bikes[MX], deg[MX];
vector<int> adj[MX];
bool vis[MX];
int n,k,cur;
vector<PII> ans;

bool cmp(int x,int y)
{
//    if(bikes[x] != bikes[y])
        return bikes[x] > bikes[y];
//    else
//        return deg[x] > deg[y];
}
void Work(int nd)
{
    int tmp=0;
//    cout << nd << " ";
    if(bikes[nd] >= k) {
        tmp = bikes[nd] - k;
        cur += tmp;
        bikes[nd] = k;
//        cout << -tmp << "\n";
        ans.pb({nd,-tmp});
    } else {
        tmp = min(k-bikes[nd], cur);
        cur -= tmp;
        bikes[nd] += tmp;
//        cout << tmp << "\n";
        ans.pb({nd,tmp});
    }
}
void dfs(int nd)
{
    vis[nd] = 1;
    Work(nd);
    for(int ch : adj[nd]) {
        if(!vis[ch]) {
            dfs(ch);
            Work(nd);
        }
    }
}
void Reset()
{
    ans.clear();
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        deg[i] = 0;
    }
}
void Solve(int tc)
{
    PII st = {1,0};
    cur = 0;
    cin >> n >> k;

    for(int i = 1; i < n; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y), adj[y].pb(x);
//        deg[x]++, deg[y]++;
    }
    for(int i = 1; i <= n; i++) {
        cin >> bikes[i];
        if(st.ss < bikes[i]) st = {i, bikes[i]};
    }
    for(int i = 1; i <= n; i++) sort(all(adj[i]),cmp);

    dfs(st.ff);

    cout << "Case " << tc << ": YES\n";
    for(auto it : ans) cout << it.ff <<" " << it.ss << "\n";
    Reset();


}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}
