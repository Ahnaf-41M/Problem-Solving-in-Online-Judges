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
   /*Always add the next cube on top of the tower with the smallest
     possible cube or create a new tower if this isn't possible.
     For, v={10, 4, 5, 9, 4, 10, 2, 7, 4, 6} answer is 4.
     (10,4,2), (5,4), (9,7,6), (10,4).*/
   int n;
   multiset<int> v;

   cin >> n;

   for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      auto it = v.upper_bound(x);
      if (it != v.end())
         v.erase(it);
      v.insert(x);
   }
   cout << v.size();
   return 0;
}