#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int a, n, ans = -101;
   scanf("%lld%lld", &a, &n);

   for (int i = 0; i <= n; i++)
      ans = max(ans, abs(__gcd(i, a)));
   printf("%lld\n", ans);

   return 0;
}