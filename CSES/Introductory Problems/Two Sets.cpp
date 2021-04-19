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
   int n, s1 = 0, s2 = 0;
   set<int> v1, v2;

   cin >> n;

   int i = n;

   while (i >= 1) {
      if (s1 + i > s2 + i)
         v2.insert(i), s2 += i;
      else
         v1.insert(i), s1 += i;
      i--;
   }
   if (s1 == s2) {
      cout << "YES\n";
      cout << v1.size() << endl;
      for (int x : v1)
         cout << x << " ";
      cout << endl << v2.size() << endl;
      for (int x : v2)
         cout << x << " ";
   }
   else
      cout << "NO\n";
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