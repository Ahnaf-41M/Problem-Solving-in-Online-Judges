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
const int NN = 1005;

char grid[NN][NN];
int dis[NN][NN];
int n, m, sx, sy;
map<pair<int, int>, pair<int, int>> par;

bool Valid(int x, int y)
{
   return (x >= 1 && x <= n && y >= 1 && y <= m && dis[x][y] == -1 && grid[x][y] != '#');
}
void bfs()
{
   queue<pair<int, int> > Q;
   Q.push({sx, sy});
   dis[sx][sy] = 0;
   par[ {sx, sy}] = { -1, -1};

   while (!Q.empty()) {
      int tx = Q.front().first;
      int ty = Q.front().second;
      Q.pop();

      if (Valid(tx + 1, ty)) {
         dis[tx + 1][ty] = dis[tx][ty] + 1;
         par[ {tx + 1, ty}] = {tx, ty};
         Q.push({tx + 1, ty});
      }
      if (Valid(tx - 1 , ty)) {
         dis[tx - 1][ty] = dis[tx][ty] + 1;
         par[ {tx - 1, ty}] = {tx, ty};
         Q.push({tx - 1, ty});
      }
      if (Valid(tx , ty + 1)) {
         dis[tx][ty + 1] = dis[tx][ty] + 1;
         par[ {tx, ty + 1}] = {tx, ty};
         Q.push({tx, ty + 1});
      }
      if (Valid(tx , ty - 1)) {
         dis[tx][ty - 1] = dis[tx][ty] + 1;
         par[ {tx, ty - 1}] = {tx, ty};
         Q.push({tx, ty - 1});
      }
   }
}
void Solve()
{
   memset(dis, -1, sizeof(dis));

   int ex, ey;
   cin >> n >> m;

   rep(i, 1, n) rep(j, 1, m) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
         sx = i, sy = j;
      if (grid[i][j] == 'B')
         ex = i, ey = j;
   }
   bfs();
   if (dis[ex][ey] == -1)
      cout << "NO\n";
   else {
      string ans = "";
      int cur_x = ex, cur_y = ey;

      while (cur_x != -1 && cur_y != -1) {
         auto it = par[ {cur_x, cur_y}];
         if (it.first != -1 && it.second != -1) {
            if ( cur_x > it.first )
               ans += 'D';
            if ( cur_x < it.first )
               ans += 'U';
            if (cur_y > it.second)
               ans += 'R';
            if (cur_y < it.second)
               ans += 'L';
         }
         cur_x = it.first;
         cur_y = it.second;
      }
      cout << "YES\n" << dis[ex][ey] << endl;
      reverse(all(ans));
      cout << ans << endl;
   }
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   //int T;
   //cin >> T;

   //while (T--)
   Solve();

   return 0;
}