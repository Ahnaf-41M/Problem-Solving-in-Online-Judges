#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int freq[130];

void Check(string s, char &odd, int &c)
{
   for (char x : s)
      freq[x]++;
   for (char ch = 'A'; ch <= 'Z'; ch++)
      if (freq[ch] & 1)
         c++, odd = ch;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   string s; cin >> s;
   if (s.size() == 1)
      cout << s;
   else {
      int c = 0;
      char odd = 'a';
      Check(s, odd, c);

      if (c > 1)
         cout << "NO SOLUTION\n";
      else {
         deque<char> ans;
         if (c) {
            while (freq[odd] > 0)
               ans.pb(odd), freq[odd]--;
         }
         for (char ch = 'A'; ch <= 'Z'; ch++) {
            int cnt = 0, tot = freq[ch];
            while (freq[ch] > 0) {
               if (cnt >= tot / 2) ans.push_back(ch);
               else ans.push_front(ch);
               cnt++; freq[ch]--;
            }
         }
         while (!ans.empty())
            cout << ans.front(), ans.pop_front();
      }
   }
   return 0;
}