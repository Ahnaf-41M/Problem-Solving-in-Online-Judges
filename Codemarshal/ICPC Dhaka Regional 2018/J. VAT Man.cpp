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

   int t;
   scanf("%lld", &t);

   while ( t-- ) {
      double n;
      scanf("%lf", &n);
      n = n + (n * .15);
      printf("%.2lf\n", n);
   }

   return 0;
}