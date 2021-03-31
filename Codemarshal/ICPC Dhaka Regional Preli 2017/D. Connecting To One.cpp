#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

struct info {
   int ind, c;
   int x, y, wt;
};

int n, m, q;
int par[41000], Rank[41000];
info adj[2 * MX];
info Q[MX];
int ans[MX];

bool cmp(info p1, info p2)
{
   return p1.wt > p2.wt;
}
bool cmp2(info p1, info p2)
{
   return p1.c > p2.c;
}

int Find(int g)
{
   if (par[g] == -1)
      return g;
   return par[g] = Find(par[g]);
}
void AnswerQueries()
{
   int j = 0, tot = 0;
   for (int i = 0; i < q; i++) {
      int cur = Q[i].c;

      while (j < m && adj[j].wt >= cur) {
         int r1 = Find(adj[j].x);
         int r2 = Find(adj[j].y);
         if (r1 != r2) {
            if (r1 == 1)
               par[r2] = r1, Rank[r1] += Rank[r2];
            else
               par[r1] = r2, Rank[r2] += Rank[r1];
            tot = Rank[1] - 1;
         }
         j++;
      }
      ans[Q[i].ind] = tot;
   }
   for (int i = 0; i < q; i++)
      printf("%lld\n", ans[i]);
   return;
}
void inputEdges()
{
   for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%lld%lld%lld", &a, &b, &w);
      adj[i].x = a, adj[i].y = b, adj[i].wt = w;
   }
   return;
}
void inputQueries()
{
   scanf("%lld", &q);
   for (int i = 0; i < q; i++) {
      int c;
      scanf("%lld", &c);
      Q[i].c = c, Q[i].ind = i;
   }
   return;
}
signed main()
{
   int t;
   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {

      scanf("%lld%lld", &n, &m);
      for (int i = 1; i <= n; i++)
         par[i] = -1, Rank[i] = 1;

      inputEdges();
      sort(adj, adj + m, cmp);

      inputQueries();
      sort(Q, Q + q, cmp2);

      printf("Case %lld:\n", k);
      AnswerQueries();

   }
   return 0;
}