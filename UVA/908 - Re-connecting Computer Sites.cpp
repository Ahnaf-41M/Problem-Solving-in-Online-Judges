#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int n, m, k, last_cst, new_cst;
vector<PII> adj[MX];
bool done[MX];

int Prims(int st)
{
   int cost = 0;
   priority_queue<PII, vector<PII>, greater<PII> > Q;
   Q.push({0, st});

   while (!Q.empty()) {
      auto cur = Q.top();
      Q.pop();

      if (done[cur.ss])
         continue;
      done[cur.ss] = 1;
      cost += cur.ff;
      // cout << cost << endl;
      for (auto ch : adj[cur.ss])
         if (!done[ch.ss])
            Q.push(ch);
   }
   return cost;
}
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   
   int tc = 0;
   while (cin >> n) {
      if(tc)
         cout << "\n";
      tc++;
      int x, y, wt, mn_wt = INT_MAX, st;
      last_cst = 0;
      for (int i = 1; i < n; i++) {
         cin >> x >> y >> wt;
         last_cst += wt;
      }
      for (int i = 1; i <= n; i++)
         adj[i].clear(), done[i] = 0;

      cin >> k;
      while (k--) {
         cin >> x >> y >> wt;
         adj[x].pb({wt, y});
         adj[y].pb({wt, x});
         if (mn_wt > wt)
            mn_wt = wt, st = x;
      }

      cin >> m;
      while (m--) {
         cin >> x >> y >> wt;
         adj[x].pb({wt, y});
         adj[y].pb({wt, x});
         if (mn_wt > wt)
            mn_wt = wt, st = x;
      }

      cout << last_cst << "\n" << Prims(st) << "\n";
   }
   return 0;
}