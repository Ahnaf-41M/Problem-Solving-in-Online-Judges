#include<bits/stdc++.h>
#define  MX      1005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

vector<int> divs[2 * MX];
bool done[2 * MX];
int lev[2 * MX], A, B;

void Pre_Cal()
{
   for (int i = 4; i <= 2 * MX - 5; i++) {
      int n = i;
      for (int j = 2; j * j <= n; j++) {
         if (n % j == 0) {
            divs[i].pb(j);
            while (n % j == 0)
               n /= j;
         }
      }
      if (n > 1 && n != i)
         divs[i].pb(n);
   }
}
void bfs()
{
   memset(lev, -1, sizeof(lev));

   queue<int> Q;
   Q.push(A);
   lev[A] = 0;

   while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (int ch : divs[cur]) {
         int nxt = ch + cur;
         if (lev[nxt] == -1 && nxt <= B) {
            lev[nxt] = lev[cur] + 1;
            Q.push(nxt);
         }
      }
   }
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   Pre_Cal();

   int t; cin >> t;

   for (int k = 1; k <= t; k++) {
      cin >> A >> B;
      bfs();
      cout << "Case " << k << ": " << lev[B] << "\n";
   }

   return 0;
}
