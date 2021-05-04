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
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n;
   deque<int> has, ans;

   cin >> n;
   for (int i = 1; i <= n; i++) has.pb(i);

   while (has.size() > 1) {
      int f = has.front(); has.pop_front();
      int s = has.front(); has.pop_front();
      ans.pb(s);
      has.pb(f);
   }
   ans.pb(has.front());
   while (!ans.empty())
      cout << ans.front() << " ", ans.pop_front();

   return 0;
}