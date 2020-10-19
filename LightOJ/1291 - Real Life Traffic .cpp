/*
(1)Find the articulation bridges in the graph.
(2)If you remove the bridges, you will get several connected components.
(3)Think carefully, there are 2 types of components.
(4)The 1st one is the connected component which had more than one bridge, if you cut one bridge,
   it still can connect with other components through other bridge.
(5)The 2nd one is the component which had only one bridge, if you cut the bridge,
   it cannot connect with other components.
(5)You may think that the answer is the number of 2nd type bridge,
   as they need another one path to connect with other components.
(6)Think carefully, you may still minimize the number of edges required.
(7)If you connect one 2nd type component to another 2nd type component,
   then it requires one edge rather than two edges.
*/
#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      10005
#define inf     1000000
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

vector<int> adj[MX];
bool inStack[MX];
int m, n, scc;
int low[MX], disc[MX], sameScc[MX], out[MX];
stack<int> S;
int Timer;

void tarjanSCC(int nd, int par)
{
   S.push(nd);

   inStack[nd] = true;
   disc[nd] = low[nd] = ++Timer;

   for (int ch : adj[nd]) {
      if (ch == par) continue;

      if (!disc[ch]) {
         tarjanSCC(ch, nd);
         low[nd] = min(low[nd], low[ch]);
      }
      else if (inStack[ch]) {
         low[nd] = min(low[nd], disc[ch]);
      }
   }
   if (low[nd] == disc[nd])
   {
      int tp = -1;
      scc++;
      while (tp != nd)
      {
         tp = S.top(); S.pop();
         inStack[tp] = false;
         sameScc[tp] = scc;
      }
   }
}
void RESET()
{
   int i;

   rep(i, 0, n) {
      inStack[i] = false; sameScc[i] = 0;
      adj[i].clear(); out[i] = 0;
      low[i] = 0; disc[i] = 0;
   }
   scc = 0; Timer = 0;
   while (!S.empty()) S.pop();
}
int main()
{
   int t, i, j;
   scanf("%d", &t);

   rep(i, 1, t + 1)
   {
      scanf("%d%d", &n, &m);
      W(m)
      {
         int x, y; scanf("%d%d", &x, &y);
         adj[x].pb(y); adj[y].pb(x);
      }
      tarjanSCC(0, -1);
      rep(j, 0, n) {
         for (int ch : adj[j]) {
            if (sameScc[j] != sameScc[ch]) {
               out[sameScc[j]]++;
               out[sameScc[ch]]++;
            }
         }
      }
      int ans = 0;
      rep(j, 1, scc + 1) ans += (out[j] == 2);
      printf("Case %d: %d\n", i, (ans + 1) / 2 );

      RESET();

   }
}