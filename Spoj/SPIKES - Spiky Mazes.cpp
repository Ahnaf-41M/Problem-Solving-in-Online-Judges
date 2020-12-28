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

char grid[50][50];
int n, m, k;
bool vis[50][50];
int dis[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool found;

bool Valid(int x, int y)
{
   if (dis[x][y] != -1)
      return false;
   return (x >= 1 && x <= n && y >= 1 && y <= m && grid[x][y] != '#');
}
void bfs(int sx, int sy)
{
   memset(dis, -1, sizeof(dis));
   deque<pair<int, int> > Q;
   Q.push_back({sx, sy});
   dis[sx][sy] = 0;

   while (!Q.empty())
   {
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop_front();

      if (grid[x][y] == 'x')
         if (dis[x][y] * 2 <= k)
            found = true;
      if (found)
         return ;

      for (int i = 0; i < 4; i++) {
         int tx = dx[i] + x;
         int ty = dy[i] + y;

         if (Valid(tx, ty)) {
            if (grid[tx][ty] == 's') {
               dis[tx][ty] = dis[x][y] + 1;
               Q.push_back({tx, ty});
            }
            else {
               dis[tx][ty] = dis[x][y];
               Q.push_front({tx, ty});
            }
         }
      }
   }
}
void solve()
{
   int sx, sy;

   cin >> n >> m >> k;
   rep(i, 1, n) {
      rep(j, 1, m) {
         cin >> grid[i][j];
         if (grid[i][j] == '@')
            sx = i, sy = j;
      }
   }
   bfs(sx, sy);

   if(found)
      cout << "SUCCESS\n";
   else
      cout << "IMPOSSIBLE\n";
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