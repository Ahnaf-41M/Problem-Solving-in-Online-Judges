#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
#define  all(v)          v.begin(),v.end()
#define  ZERO(a)         memset(a,0,sizeof(a))
#define  MINUS(a)        memset(a,-1,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

char grid[12][12], current;
bool vis[12][12];
int level[12][12];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, ex, ey;
map<char, int> mp;
char cur;
bool is_valid(int x, int y)
{
   int dif = 0;

   if (grid[x][y] >= 'A' && grid[x][y] <= 'Z')
      dif = (grid[x][y] - 64) - (cur - 64);
   if (x < 0 || x >= n || y < 0 || y >= n)
      return false;
   if (grid[x][y] == '#' || vis[x][y] || dif > 1)
      return false;
   return true;
}
int bfs(int sx, int sy)
{
   int i;
   char current_char = (char)(cur + 1);
   queue<pair<int, int>> Q;
   Q.push({sx, sy});

   while ( !Q.empty() )
   {
      int tx = Q.front().first;
      int ty = Q.front().second;
      Q.pop();

      rep(i, 0, 4) {

         int x = tx + dx[i];
         int y = ty + dy[i];

         if (is_valid(x, y)) {
            Q.push({x, y});
            vis[x][y] = true;
            level[x][y] = level[tx][ty] + 1;

            // cout << current_char << " " << grid[x][y] << endl;
            if (current_char == grid[x][y]) {
               return level[x][y];
            }
         }
      }
   }
   return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int t, i, k, j;

   scanf("%d", &t);

   rep(k, 1, t + 1)
   {
      scanf("%d", &n);
      int tot_ch = 0;
      map<char, pair<int, int>> pos;

      rep(i, 0, n) {
         rep(j, 0, n) {
            cin >> grid[i][j];
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
               tot_ch++;
               pos[grid[i][j]] = {i, j};
            }
         }
      }

      bool ok = true;
      int ans = 0;
      rep(i, 0, tot_ch - 1) {

         auto id = pos['A' + i];
         int sx = id.ff, sy = id.ss;
         cur = 'A'+i;
         int res = bfs(sx, sy);
         if (res == -1) {
            ok = false;
            break;
         }
         ans += res;
         ZERO(vis); ZERO(level);
      }
      if (!ok)
         printf("Case %d: Impossible\n", k);
      else
         printf("Case %d: %d\n", k, ans);
      ZERO(grid); ZERO(level); ZERO(vis);
   }
}