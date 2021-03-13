#include<bits/stdc++.h>
#define  MX      105
#define  pb      push_back
#define  ff      first
#define  ss      second
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

vector<PII> adj[MX];
bool vis[MX];
int st, ed;
int mx_ton;

void Prims()
{
   priority_queue<PII> Q;
   Q.push({0, st});
   mx_ton = INT_MAX;
   while (!Q.empty()) {
      auto it = Q.top();
      Q.pop();

      if (vis[ed])
         break;
      if (vis[it.ss])
         continue;

      vis[it.ss] = 1;
      if (it.ff)
         mx_ton = min(mx_ton, it.ff);
      for (auto ch : adj[it.ss])
         if (!vis[ch.ss])
            Q.push(ch);
   }
}
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   int n, r, tc = 1;

   while (cin >> n >> r) {
      if (!n && !r)
         break;

      map<string, int> cityIndex;
      int cnt = 1;

      mx_ton = 0;
      for (int i = 1; i <= n; i++) {
         adj[i].clear();
         vis[i] = 0;
      }

      while (r--) {
         string s1, s2;
         int wt;
         cin >> s1 >> s2 >> wt;
         if (!cityIndex[s1])
            cityIndex[s1] = cnt++;
         if (!cityIndex[s2])
            cityIndex[s2] = cnt++;
         int x = cityIndex[s1];
         int y = cityIndex[s2];

         adj[x].pb({wt, y});
         adj[y].pb({wt, x});
      }

      string s1, s2;
      cin >> s1 >> s2;
      st = cityIndex[s1], ed = cityIndex[s2];

      Prims();
      cout << "Scenario #" << tc++ << "\n"
           << mx_ton << " tons\n\n";
   }

   return 0;
}