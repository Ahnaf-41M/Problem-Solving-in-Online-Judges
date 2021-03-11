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

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool Valid(int x, int y)
{
   return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}
void Solve(int k)
{
   int r, c, cnt = 0;

   cin >> r >> c;
   rep(i, 0, 7) {
      int x = r + dx[i];
      int y = c + dy[i];
      if (Valid(x, y))
         cnt++;
   }
   cout << "Case " << k << ": " << cnt << endl;
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