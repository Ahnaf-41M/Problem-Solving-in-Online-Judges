#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;


struct info
{
   int two, five;
} fact[MX + 5];

int Fun1(int x)
{
   int cnt = 0;
   while (x % 2 == 0)
      x /= 2, cnt++;
   return cnt;
}
int Fun2(int x)
{
   int cnt = 0;
   while (x % 5 == 0)
      x /= 5, cnt++;
   return cnt;
}
void Pre_Cal()
{
   for (int i = 2; i <= MX; i++) {
      fact[i].two = fact[i - 1].two + Fun1(i); //number of 2s in the factorization of fact[i]
      fact[i].five = fact[i - 1].five + Fun2(i); //number of 5s in the factorization of fact[i]
   }
}

int n, r, p, q;
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   Pre_Cal();

   int t;
   cin >> t;

   for (int k = 1; k <= t; k++) {
      cin >> n >> r >> p >> q;

      int p_2 = Fun1(p) * q, p_5 = Fun2(p) * q;
      int d1 = fact[n].two - (fact[n - r].two + fact[r].two);
      int d2 = fact[n].five - (fact[n - r].five + fact[r].five);

      int ans = min(d1 + p_2, d2 + p_5);
      cout << "Case " << k << ": " << ans << endl;

   }
   return 0;
}
