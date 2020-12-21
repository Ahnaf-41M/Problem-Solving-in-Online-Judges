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
   int n;
   cin >> n;

   W(n)
   {
      string s;
      map<char, int> freq;
      int ans = 0;

      cin >> s;

      rep(i, 0, s.size() - 1) {
         if (s[i] == 'K' || s[i] == 'E')
            freq[s[i]]++;
      }

      int till_k = 0;
      rep(i, 0, s.size() - 1) {
         if (s[i] == 'K')
            till_k++;
         else if (s[i] == 'E') {
            int left_k = freq['K'] - till_k;
            ans += (left_k * till_k);
         }
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