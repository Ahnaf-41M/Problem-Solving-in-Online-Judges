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
   int m;
   string s;

   while (cin >> m && m)
   {
      unordered_map<char, int> freq;
      int cur_L = 0, ans = 0, last = 0;

      cin.ignore(256, '\n');
      getline(cin, s);


      rep(i, 0, s.size() - 1) {
         freq[s[i]]++;
         cur_L++;

         if (freq.size() > m) {
            while (last <= i) {
               freq[s[last]]--;
               if (freq[s[last]] == 0)
                  break;
               cur_L--, last++;
            }
            freq.erase(s[last]);
            cur_L--, last++;
         }
         ans = max(cur_L, ans);
      }

      cout << ans << endl;

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