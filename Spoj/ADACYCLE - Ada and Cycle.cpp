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

const int N = 2500;

vector<int> adj[N];
int dis[N];

void bfs(int src)
{
   memset(dis, -1, sizeof(dis));
   queue<int> Q;
   Q.push(src);
   dis[src] = 0;

   while (!Q.empty()) {
      int node = Q.front();
      Q.pop();

      for (int ch : adj[node]) {
         if (dis[ch] == -1) {
            dis[ch] = dis[node] + 1;
            Q.push(ch);
         }
         if (ch == src) {
            dis[src] = dis[node] + 1;
            return ;
         }
      }
   }
}
void solve()
{
   int n;
   cin >> n;

   rep(i, 1, n) {
      rep(j, 1, n) {
         int x;
         cin >> x;
         if (x)
            adj[i].pb(j);
      }
   }

   rep(i, 1, n) {
      bfs(i);
      if (dis[i] == 0)
         cout << "NO WAY\n";
      else
         cout << dis[i] << endl;
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