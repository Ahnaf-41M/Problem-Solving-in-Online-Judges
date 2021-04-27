#include <bits/stdc++.h>
#define  pb push_back
#define  mx 100005
using namespace std;

vector<int> adj[mx], euler;
int LCA[mx][22];
int par[mx], lev[mx], ans[mx];
int n, m, q, sz, in_Time[mx], out_Time[mx], res;
int freq_wt[mx], freq_nd[mx], weight[mx];
bool vis[mx];
int timer = 1;
const int block = 700;

struct Query
{
   int L, R, indx, lca;
};
Query Q[mx];

bool cmp2(pair<int, int> x, pair<int, int> y)
{
   return x.first < y.first;
}
void init()
{
   sz = log2(n) + 1;

   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= sz; j++)
         LCA[i][j] = -1;

   vector<pair<int, int>> vp;
   for (int i = 1; i <= n; i++) {
      cin >> weight[i];
      vp.pb({weight[i], i});
   }
   //co-ordinate compression
   sort(vp.begin(), vp.end(), cmp2);
   int last = -1, cnt = 0;
   for (auto it : vp) {
      if (last == it.first)
         weight[it.second] = cnt;
      else {
         weight[it.second] = ++cnt;
         last = it.first;
      }
   }

   for (int i = 0; i < n - 1; i++)
   {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
}
void dfs(int nd, int pr)
{
   euler.pb(nd);
   in_Time[nd] = timer++;
   LCA[nd][0] = pr;

   for (int ch : adj[nd])
      if (ch != pr) {
         par[ch] = nd;
         lev[ch] = lev[nd] + 1;
         dfs(ch, nd);
      }
   euler.pb(nd);
   out_Time[nd] = timer++;
}
void buildLCA()
{
   for (int j = 1; j <= sz; j++) {
      for (int i = 1; i <= n; ++i) {
         if (LCA[i][j - 1] != -1) {
            int pp = LCA[i][j - 1];
            LCA[i][j] = LCA[pp][j - 1];
         }
      }
   }
}
int findLCA(int a, int b)
{
   if (lev[a] > lev[b])
      swap(a, b);
   int d = lev[b] - lev[a];

   while (d > 0)
   {
      int i = log2(d);
      b = LCA[b][i];
      d -= (1 << i);
   }
   if (a == b) return a;

   for (int i = sz; i >= 0; i--)
      if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
         a = LCA[a][i], b = LCA[b][i];
   return par[a];
}
bool cmp(Query a, Query b)
{
   if (a.L / block != b.L / block)
      return a.L < b.L;
   return a.R < b.R;
}
void Add(int pos)
{
   int node = euler[pos];
   int val = weight[node];
   freq_nd[node]++;
   if (freq_nd[node] == 1) {
      freq_wt[val]++;
      if (freq_wt[val] == 1)
         res++;
   }
   else {
      freq_wt[val]--;
      if (!freq_wt[val])
         res--;
   }
}
void Remove(int pos)
{
   int node = euler[pos];
   int val = weight[node];
   freq_nd[node]--;
   if (freq_nd[node] == 1) {
      freq_wt[val]++;
      if (freq_wt[val] == 1)
         res++;
   }
   else {
      freq_wt[val]--;
      if (!freq_wt[val])
         res--;
   }
}
void AnswerQueries()
{
   int cur_L = 1, cur_R = 0;

   for (int i = 1; i <= m; i++) {
      int left = Q[i].L;
      int right = Q[i].R;
      int lca = Q[i].lca;

      while (cur_L > left) Add(--cur_L);
      while (cur_R < right) Add(++cur_R);

      while (cur_L < left) Remove(cur_L++);
      while (cur_R > right) Remove(cur_R--);

      if (lca != -1 && !freq_wt[weight[lca]])
         ans[Q[i].indx] = res + 1;
      else
         ans[Q[i].indx] = res;
   }
   for (int i = 1; i <= m; i++)
      cout << ans[i] << "\n";
}
void RESET()
{
   for (int i = 0; i <= n + 1; i++) {
      adj[i].clear();
      vis[i] = false;
      lev[i] = 0;
      in_Time[i] = out_Time[i] = 0;
      freq_wt[i] = freq_nd[i] = 0;
      par[i] = weight[i] = 0;
      for (int j = 0; j < 22; j++)
         LCA[i][j] = 0;
   }
   for (int i = 1; i <= m; i++) {
      ans[i] = 0;
      Q[i].L = Q[i].R = Q[i].indx = 0;
      Q[i].lca = 0;
   }
   timer = 1;
   euler.clear();
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   /*First, flatten the tree into an array(euler). Store in time and out time
   of nodes.
   Case 1: if LCA(x,y) = x, then l = in_Time[x] and r = in_Time[y].
   Case 2: if LCA(x,y) != x, then l = out_Time[x], r = in_Time[y].
   For both the cases, nodes that occurs zero/twice in the range
   from l to r won't be counted. */
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 0;

   while (cin >> n >> m) {
      euler.pb(0);
      init();
      dfs(1, -1);
      buildLCA();

      for (int i = 1; i <= m; i++)
      {
         int x, y, c; cin >> x >> y;
         if (in_Time[x] > in_Time[y])
            swap(x, y);
         Q[i].indx = i;
         Q[i].lca = findLCA(x, y);
         // cout << "LCA(" << x << "," << y << "): " << findLCA(x, y) << endl;
         if (Q[i].lca == x) {
            Q[i].lca = -1;
            Q[i].L = in_Time[x];
            Q[i].R = in_Time[y];
         }
         else {
            Q[i].L = out_Time[x];
            Q[i].R = in_Time[y];
         }
      }
      sort(Q + 1, Q + 1 + m, cmp);
      AnswerQueries();
      RESET();
   }

}
