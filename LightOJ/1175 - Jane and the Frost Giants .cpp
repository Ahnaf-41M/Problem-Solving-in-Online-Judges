/*For every minute we need to find the positions the fires spreads.
  Then, for every minute we are finding the positions where Jane 
  can go. Jane can't go to a position where the position is already
  burning(we are checking that thing in Valid2() function). 
  Finally, from all the border positions we are finding the minimum
  one. */
#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int r, c, jx, jy, fx, fy;
char maze[205][205];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int lev1[205][205], lev2[205][205];
vector<PII> fires;

bool Valid1(int x, int y)
{
   return (x >= 1 && x <= r && y >= 1 && y <= c && maze[x][y] == '.'
           && lev1[x][y] == -1);
}
bool Valid2(int x, int y, int Lv)
{
   return (x >= 1 && x <= r && y >= 1 && y <= c && maze[x][y] == '.' &&
           lev2[x][y] == -1 && (lev1[x][y] == -1 || 1 + Lv < lev1[x][y]));
}
void bfs(int tp)
{
   queue<PII> Q;
   if (tp == 2) {
      Q.push({jx, jy});
      lev2[jx][jy] = 0;
   }
   else {
      for (auto it : fires) {
         Q.push(it);
         lev1[it.first][it.second] = 0;
      }
   }

   while (!Q.empty()) {
      int cur_x = Q.front().first;
      int cur_y = Q.front().second;
      Q.pop();

      for (int i = 0; i < 4; i++) {
         int tx = dx[i] + cur_x;
         int ty = dy[i] + cur_y;

         if (tp == 1) {
            if (Valid1(tx, ty)) {
               Q.push({tx, ty});
               lev1[tx][ty] = lev1[cur_x][cur_y] + 1;
            }
         }
         else {
            if (Valid2(tx, ty, lev2[cur_x][cur_y])) {
               Q.push({tx, ty});
               lev2[tx][ty] = lev2[cur_x][cur_y] + 1;
            }
         }
      }
   }
}
void Check(int &mn)
{
   //Check the borders of the maze and find the minimum
   for (int i = 1; i <= r; i++) {
      if (lev2[i][1] != -1 && mn > lev2[i][1])
         mn = lev2[i][1];
      if (lev2[i][c] != -1 && mn > lev2[i][c])
         mn = lev2[i][c];
   }
   for (int i = 1; i <= c; i++) {
      if (lev2[1][i] != -1 && mn > lev2[1][i])
         mn = lev2[1][i];
      if (lev2[r][i] != -1 && mn > lev2[r][i])
         mn = lev2[r][i];
   }
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   memset(lev1, -1, sizeof(lev1));
   memset(lev2, -1, sizeof(lev2));

   int t;
   cin >> t;

   for (int k = 1; k <= t; k++) {
      cin >> r >> c;
      for (int i = 1; i <= r; i++) {
         for (int j = 1; j <= c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'J')
               jx = i, jy = j;
            if (maze[i][j] == 'F')
               fires.pb({i, j});
         }
      }

      bfs(1);
      bfs(2);

      int mn = 1e18;

      Check(mn);

      cout << "Case " << k << ": ";
      if (mn != 1e18)
         cout << mn + 1 << "\n";
      else
         cout << "IMPOSSIBLE\n";

      for (int i = 1; i <= r; i++)
         for (int j = 1; j <= c; j++)
            lev1[i][j] = lev2[i][j] = -1;
      fires.clear();
   }

   return 0;
}