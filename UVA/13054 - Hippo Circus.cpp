#include <bits/stdc++.h>
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

void Solve(int tc)
{
   int N, H, Ta, Td, ans = 0;
   cin >> N >> H >> Ta >> Td;

   int ar[N];

   rep(i, 0, N - 1) cin >> ar[i];
   sort(ar, ar + N);

   int i = 0, j = N - 1;
   while (i <= j) {
      if (ar[i] + ar[j] < H && 2 * Ta >= Td) {
         if (i == j) ans += Ta;
         else ans += Td;
         i++, j--;
      }
      else
         j--, ans += Ta;
   }
   cout << "Case " << tc << ": " << ans << "\n";
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}