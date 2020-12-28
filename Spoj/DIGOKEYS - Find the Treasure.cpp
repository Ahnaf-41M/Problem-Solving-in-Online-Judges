#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)
#define  irep(i,a,b)     for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

vector<int> adj[MX];
int n, m, dis[MX], parent[MX];
stack<int> seq;

void bfs()
{
   dis[1] = 0;

   queue<int> Q;
   Q.push(1);

   while (!Q.empty()) {
      int nd = Q.front();
      Q.pop();

      for (int ch : adj[nd]) {
         if (dis[ch] == -1) {
            dis[ch] = dis[nd] + 1;
            parent[ch] = nd;
            Q.push(ch);
         }
      }
   }

   int cur = parent[n];
   while (cur != -1) {
      seq.push(cur);
      cur = parent[cur];
   }
}
void reset()
{
   rep(i, 1, n) {
      adj[i].clear();
      dis[i] = -1;
      parent[i] = -1;
   }
   while (!seq.empty())
      seq.pop();
   memset(dis, -1, sizeof(dis));
   memset(parent, -1, sizeof(parent));
}
void solve()
{
   int t;
   cin >> t;

   memset(dis, -1, sizeof(dis));
   memset(parent, -1, sizeof(parent));

   W(t)
   {
      cin >> n;
      rep(i, 1, n - 1) {
         cin >> m;
         W(m) {
            int x;
            cin >> x;
            adj[i].pb(x);
         }
      }
      rep(i, 1, n - 1) sort(all(adj[i]));

      bfs();

      if (dis[n] == -1)
         cout << "-1\n";
      else {
         cout << seq.size() << endl;
         while (!seq.empty()) {
            cout << seq.top() << " ";
            seq.pop();
         }
         cout << endl;
      }

      reset();
   }

   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   solve();

   return 0;
}