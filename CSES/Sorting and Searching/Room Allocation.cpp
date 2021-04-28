#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

struct info
{
   int a, b, ind;
} ar[2 * MX];
struct info2
{
   int b, ind;
};
struct check
{
   bool operator()(info2 g, info2 h) {
      return g.b > h.b;
   }
};
int ans[2 * MX];

bool cmp(info x, info y)
{
   if (x.a == y.a)
      return x.b < y.b;
   return x.a < y.a;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, rooms = 0, till = 0;
   cin >> n;

   for (int i = 0; i < n; i++) {
      cin >> ar[i].a >> ar[i].b;
      ar[i].ind = i;
   }
   sort(ar, ar + n, cmp);

   priority_queue<info2, vector<info2>, check > cur;
   stack<int> available;

   for (int i = 0; i < n; i++) {
      int j = ar[i].ind;
      // cout << ar[i].a << "--> " << ar[i].b << " -> " << j << "\n";
      while (!cur.empty() && ar[i].a > cur.top().b)
         available.push(cur.top().ind), cur.pop();
      if (available.size()) {
         ans[j] = available.top();
         available.pop();
      }
      else {
         ans[j] = ++till;
         rooms = till;
      }
      cur.push({ar[i].b, ans[j]});
   }
   cout << rooms << "\n";
   for (int i = 0; i < n; i++)
      cout << ans[i] << " ";
   return 0;
}