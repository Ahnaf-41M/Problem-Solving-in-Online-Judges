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

void Solve()
{
   int n, x;
   map<int, int> pos;

   cin >> n >> x;
   int ar[n + 1];

   rep(i, 1, n) {
      cin >> ar[i];
      if (pos[ar[i]]) {
         if (ar[i] + ar[i] == x) {
            cout << i << " " << pos[ar[i]];
            return;
         }
      }
      pos[ar[i]] = i;
   }
   rep(i, 1, n) {
      if (pos[x - ar[i]] && pos[ar[i]] != pos[x - ar[i]]) {
         cout << pos[ar[i]] << " " << pos[x - ar[i]];
         return;
      }
   }
   cout << "IMPOSSIBLE\n";
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