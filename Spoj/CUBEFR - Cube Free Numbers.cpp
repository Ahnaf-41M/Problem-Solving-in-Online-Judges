#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int nxt[MX], pos[MX];
void Sieve()
{
   nxt[1] = 1;
   for (int i = 2; i < MX; i++) {
      if (!nxt[i]) {
         nxt[i] = i;
         for (int j = i * i; j < MX; j += i)
            nxt[j] = i;
      }
   }
}
int Not_Qube(int n)
{
   while (n != 1) {
      int pf = nxt[n], cnt = 0;
      while (n % pf == 0)
         n /= pf, cnt++;
      if (cnt >= 3) return 0;
   }
   return 1;
}
void Generate()
{
   int cnt = 1;
   rep(i, 1, MX - 1) {
      if (Not_Qube(i))
         pos[i] = cnt++;
   }
}
void Solve(int tc)
{
   int n;
   cin >> n;

   cout << "Case " << tc << ": ";
   if (pos[n]) cout << pos[n];
   else cout << "Not Cube Free";
   cout << "\n";
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   Sieve();
   Generate();

   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}