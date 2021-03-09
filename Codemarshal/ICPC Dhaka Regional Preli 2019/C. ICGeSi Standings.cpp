#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

struct info
{
   int id, S, TP, M;
};
void Solve(int k)
{
   int n;
   vector<int> frozen[52], rank;

   cin >> n;

   info ar[n + 1];
   int pos[n + 1];

   rep(i, 1, n) {
      frozen[i].pb(0);
      cin >> ar[i].id >> ar[i].S >> ar[i].TP >> ar[i].M;
      pos[ar[i].id] = i;

      rep(j, 1, ar[i].M) {
         int x; cin >> x;
         frozen[i].pb(frozen[i].back() + x);
      }
   }
   rep(i, 1, n) {
      int x; cin >> x;
      rank.pb(x);
   }

   int last_s = 0, last_tp = 0;
   bool ok = 1;

   for (int x : rank) {
      int cur = pos[x];
      if (!last_s) {
         last_s = ar[cur].M + ar[cur].S;
         last_tp = frozen[cur].back() + ar[cur].TP;
      }
      else {
         if ((last_s == ar[cur].S && last_tp > ar[cur].TP)
               || (last_s < ar[cur].S)) {
            ok = 0;
            break;
         }
         int MM = ar[cur].M, cur_s = ar[cur].S, cur_tp = ar[cur].TP;
         int nxt_s = cur_s, nxt_tp = cur_tp;

         rep(i, 1, MM) {
            if ((cur_s + i < last_s)
            || (cur_s + i == last_s && cur_tp + frozen[cur][i] >= last_tp))
               nxt_s = cur_s + i, nxt_tp = cur_tp + frozen[cur][i];
            else
               break;
         }
         last_s = nxt_s, last_tp = nxt_tp;
      }
   }

   if (ok)
      cout << "Case " << k << ": We respect our judges :)\n";
   else
      cout << "Case " << k << ": Say no to rumour >:\n";
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;

   rep(k, 1, T) {
      Solve(k);
   }

   return 0;
}