#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int MOD = 1e9 + 7;

int Power(int a, int p)
{
   int res = 1;
   while (p) {
      if (p & 1) res = res * a % MOD;
      a = a * a % MOD;
      p >>= 1;
   }
   return res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n; cin >> n;
   cout << Power(2, n);

   return 0;
}