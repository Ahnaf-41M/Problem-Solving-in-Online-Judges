#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)
#define  irep(i,a,b)     for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

void solve(int tt)
{
   int n, q, cnt = 0;
   string s1, s2 = "#";

   cin >> n >> s1;
   s2 += s1;

   for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
      if (s1[i] == s1[j])
         cnt++;

   cin >> q;

   cout << "Case " << tt << ":\n";
   int mid = (n + 1) >> 1;

   W(q)
   {
      int indx;
      char ch;

      cin >> indx >> ch;

      if (n & 1 && mid == indx)
         cout << (cnt == n ? "YES\n" : "NO\n");
      else {
         if (s2[indx] == s2[n - indx + 1]) {
            s2[indx] = ch;
            if (s2[indx] != s2[n - indx + 1])
               cnt -= 2;
            cout << (cnt == n ? "YES\n" : "NO\n");
         }
         else {
            s2[indx] = ch;
            if (s2[indx] == s2[n - indx + 1])
               cnt += 2;
            cout << (cnt == n ? "YES\n" : "NO\n");
         }
      }
   }
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int tt;
   cin >> tt;

   rep(i, 1, tt) {
      solve(i);
   }

   return 0;
}