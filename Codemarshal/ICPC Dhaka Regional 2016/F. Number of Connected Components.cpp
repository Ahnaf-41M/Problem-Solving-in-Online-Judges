#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

bitset < MX + 5 > OK, vis;
vector<int> v, adj[MX];
int n, ar[MX];
int ans;
void Sieve()
{
   for (int i = 3; i <= MX; i += 2)
      OK[i] = 1;
   for (int i = 3; i * i <= MX; i += 2)
      if (OK[i])
         for (int j = i * i; j <= MX; j += i)
            OK[j] = 0;
   v.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (OK[i])
         v.pb(i);
}
void Factorize(set<int> &primes, int x)
{
   int j = 0, m = x;
   while (j < v.size() && v[j]*v[j] <= x) {
      if (x % v[j] == 0) {
         primes.insert(v[j]);
         adj[v[j]].pb(m);
         adj[m].pb(v[j]);
         while (x % v[j] == 0)
            x /= v[j];
      }
      j++;
   }
   if (x > 1) {
      adj[x].pb(m);
      adj[m].pb(x);
      primes.insert(x);
   }
}
void dfs(int nd)
{
   vis[nd] = 1;
   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
void RESET()
{
   for (int i = 1; i <= n; i++)
      vis[ar[i]] = 0, adj[ar[i]].clear();
   ans = 0;
}
signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);

   Sieve();

   int t;
   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {
      set<int> primes;
      scanf("%lld", &n);

      for (int i = 1; i <= n; i++) {
         scanf("%lld", &ar[i]);
         Factorize(primes, ar[i]);
         ans += (ar[i] == 1);
         vis[1] = 1;
      }

      for (int x : primes)
         if (!vis[x])
            dfs(x), ans++;

      printf("Case %lld: %lld\n", k, ans);

      for (int x : primes)
         vis[x] = 0, adj[x].clear();
      RESET();
   }

   return 0;
}