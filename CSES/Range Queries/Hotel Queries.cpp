#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int hotel[2 * MX], group[2 * MX], tree[6 * MX];
int n, m;

void Build(int node, int b, int e)
{
   if (b == e) {
      tree[node] = hotel[b];
      return;
   }
   int left = (node << 1);
   int right = (node << 1) + 1;
   int mid = (b + e) >> 1;

   Build(left, b, mid);
   Build(right, mid + 1, e);
   tree[node] = max(tree[left], tree[right]);
}
void QueryUpd(int node, int b, int e, int val)
{
   if (b == e) {
      tree[node] -= val;
      printf("%lld ", b);
      return;
   }
   int left = (node << 1);
   int right = (node << 1) + 1;
   int mid = (b + e) >> 1;

   if (tree[left] >= val) QueryUpd(left, b, mid, val); //we want the first value
   else QueryUpd(right, mid + 1, e, val);
   tree[node] = max(tree[left], tree[right]);

}
signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);

   scanf("%lld%lld", &n, &m);
   for (int i = 1; i <= n; i++) scanf("%lld", &hotel[i]);
   for (int i = 1; i <= m; i++) scanf("%lld", &group[i]);

   Build(1, 1, n);

   for (int i = 1; i <= m; i++) {
      int cur = group[i];
      if (tree[1] < cur) printf("0 ");  //if there is no hotel with rooms >= group[i]
      else QueryUpd(1, 1, n, cur);
   }
   return 0;
}
