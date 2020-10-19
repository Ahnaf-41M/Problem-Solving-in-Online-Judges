#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int LCA[100010][20];
int n, q, nd_val[100010];

void buildLCA()
{
   for (int j = 1; (1 << j) < n; j++) {
      for (int i = 0; i < n; i++) {
         if (LCA[i][j - 1] != -1) {
            int par = LCA[i][j - 1];
            LCA[i][j] = LCA[par][j - 1];
         }
      }
   }

}
int Query(int node, int val)
{
   int sz = log2(n);

   for (int j = sz; j >= 0; j--) {
      int cur_par = LCA[node][j];
      if (cur_par != -1 && nd_val[cur_par] >= val) {
         node = LCA[node][j];
      }
   }
   return node;
}
void CLEAR()
{
   int sz = log2(n);
   int i, j;

   rep(i, 0, n) {
      nd_val[i] = 0;
      rep(j, 0, sz + 1) {
         LCA[i][j] = -1;
      }
   }
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   memset(LCA, -1, sizeof(LCA));
   int t, i, j, k;
   scanf("%d", &t);

   rep(k, 1, t + 1)
   {
      scanf("%d%d", &n, &q);
      nd_val[0] = 1;

      rep(i, 1, n) {
         int x, w;
         scanf("%d%d", &x, &w);
         nd_val[i] = w;
         LCA[i][0] = x;
      }

      buildLCA();

      printf("Case %d:\n", k);

      W(q)
      {
         int node, val; scanf("%d%d", &node, &val);
         printf("%d\n", Query(node, val));
      }
      CLEAR();
   }

   return 0;
}

