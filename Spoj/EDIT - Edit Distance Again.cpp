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

void solve()
{
   string s;

   while (cin >> s)
   {
      int diff1 = 0, diff2 = 0, cnt = 0, last = -1;
      int n = s.size();
      string str1 = "", str2 = "", str3 = "";

      rep(i, 0, n - 1) {
         if (i & 1) {
            str2 += '1';
            str3 += '0';
         }
         else {
            str2 += '0';
            str3 += '1';
         }

         if (s[i] >= 'A' && s[i] <= 'Z')
            str1 += '1';
         else
            str1 += '0';
      }
      rep(i, 0, n - 1) {
         diff1 += (str1[i] != str2[i]);
         diff2 += (str1[i] != str3[i]);
      }
      cout << min(diff2, diff1) << endl;
   }

   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   solve();

   return 0;
}