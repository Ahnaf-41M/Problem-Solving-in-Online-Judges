#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  pb            push_back
#define  ll           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using ordered_set =
   tree<T, null_type, less_equal<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

int Parent[MX + 5], Rank[MX + 5];
ordered_set<int> adj[MX];

int Root(int x)
{
   if (Parent[x] == -1)
      return x;
   else return Parent[x] = Root(Parent[x]);
}

int main()
{
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);

   int T;
   scanf("%d", &T);

   rep(k, 1, T) {
      int n, q, type = 0;

      rep(i, 1, MX) {
         Parent[i] = -1;
         Rank[i] = 1;
      }

      scanf("%d%d", &n, &q);
      rep(i, 1, n) adj[i].clear();

      printf("Case %d:\n", k);
      while (q--) {
         int U, V, T, L, R;
         scanf("%d", &type);

         if (type == 0) {
            scanf("%d%d", &U, &V);
            int r1 = Root(U);
            int r2 = Root(V);

            if (r1 != r2) {
               if (Rank[r1] < Rank[r2])
                  swap(r1, r2);
               Parent[r2] = r1;
               Rank[r1] += Rank[r2];
               for (int ch : adj[r2])
                  adj[r1].insert(ch);
            }
         }
         else if (type == 1) {
            scanf("%d%d", &U, &T);
            int r = Root(U);
            adj[r].insert(T);
         }
         else {
            scanf("%d%d%d", &U, &L, &R);
            int r = Root(U);
            ll res = 0;

            if (adj[r].size()) {
               int left = adj[r].order_of_key(L);
               int right = adj[r].order_of_key(R + 1);
               // cout << "left:: " << left << " right:: " << right << endl;
               res += (right - left);
            }
            printf("%lld\n", res);
         }
      }
   }

   return 0;
}