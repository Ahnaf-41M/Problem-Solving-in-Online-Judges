#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

bool Hexa(string s)
{
   for (int i = 0; i < s.size(); i++)
      if (s[i] >= 'A' && s[i] <= 'F' || s[i] == 'x')
         return true;
   return false;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   string s;
   int t;

   while (cin >> s >> t) {
      if (s.size() == 1 && s[0] == '0' && !t)
         break;
      int n = 0;
      if (s[0] == '0') {
         if (Hexa(s)) {
            stringstream geek;
            geek << hex << s;
            geek >> n;
         }
         else {
            int base = 1;
            for (int i = s.size() - 1; i >= 0; i--) {
               int dig = s[i] - '0';
               n += base * dig;
               base *= 8;
            }
         }
      }
      else
         n = stoi(s);

      int ans = 0;
      while (t--) {
         string s2; int cur;
         cin >> s2 >> cur;

         if (s2.size() == 1) {
            if (cur == n)
               ans++;
            else
               n = cur;
         }
         else if (s2[0] == '+' || s2[0] == '-') {
            if (s2[0] == '+') n++;
            else n--;
            if (n != cur)
               n = cur;
            else
               ans++;
         }
         else {
            if (n != cur)
               n = cur;
            else
               ans++;
            if (s2[s2.size() - 1] == '+') n++;
            else n--;
         }
      }
      cout << ans << endl;
   }

   return 0;
}