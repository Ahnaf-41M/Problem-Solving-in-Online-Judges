#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  pi      acos(-1)
#define  MOD     1000000007
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int p, q, y; cin >> p >> q >> y;
   p *= 5; q *= 2;
   y *= 52;
   y = (p + q) * y;
   cout << y << "\n";
   return 0;
}