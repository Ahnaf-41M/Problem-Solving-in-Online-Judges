#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      100005
#define inf     1000000
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

struct info
{
   int sum, prop;
} tree[3 * MX];
string s, tmp;

void build(int node, int b, int e)
{
   if (b == e){
      tree[node].sum = tmp[b] - '0';
      return;
   }

   int left = node << 1;
   int right = (node << 1) + 1;
   int mid = (b + e) >> 1;

   build(left, b, mid);
   build(right, mid + 1, e);

   tree[node].sum = tree[left].sum + tree[right].sum;
}
void update(int node, int b, int e, int L, int R)
{
   if (b > e) return;  
   if (b > R || e < L) return;

   if (b >= L && e <= R) {
      tree[node].sum += (e - b + 1);
      tree[node].prop += 1;
      return;
   }
   int left = node << 1;
   int right = (node << 1) + 1;
   int mid = (b + e) >> 1;

   update(left, b, mid, L, R);
   update(right, mid + 1, e, L, R);

   tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (e - b + 1);
}
int Query(int node, int b, int e, int ind, int carry = 0)
{
   if (b > e) return 0;
   if (b > ind || e < ind) return 0;
   if (b == ind && ind == e) return tree[node].sum + carry * (e - b + 1);

   int left = node << 1;
   int right = (node << 1) + 1;
   int mid = (b + e) >> 1;

   int r1 = Query(left, b, mid, ind, carry + tree[node].prop);
   int r2 = Query(right, mid + 1, e, ind, carry + tree[node].prop);

   return r1 + r2;
}
int main()
{
   int t, i, j, k, q, n;
   scanf("%d", &t);

   rep(k, 1, t + 1)
   {
      cin >> s; n = s.size();
      tmp = "a"; tmp += s;

      build(1, 1, n);
      printf("Case %d:\n", k);
      scanf("%d", &q);

      W(q)
      {
         char type[2]; scanf("%s",type);
         if (type[0] == 'I') {
            int x, y; scanf("%d%d", &x, &y);
            update(1, 1, n, x, y);
         }
         else {
            int ind; scanf("%d", &ind);
            int ans = Query(1, 1, n, ind);
            printf("%d\n", ans % 2);
         }
      }
      ZERO(tree);
   }
}