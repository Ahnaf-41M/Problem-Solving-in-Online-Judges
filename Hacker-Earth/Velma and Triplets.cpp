#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  ZERO(a)         memset(a,0,sizeof(a))
#define  MINUS(a)        memset(a,-1,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
   IOS
   ll n, i, x, ans = 0;
   ll one = 0, two = 0, three = 0, extra = 0;

   cin >> n;

   W(n)
   {
      cin >> x;
      if (x == 1) one++;
      else if (x == 2) two++;
      else if (x == 3) three++;
      else extra++;
   }
   //for 1,1,1 (nC3 * 3)
   ans += ((one * (one - 1) * (one - 2)) / 6) * 3; 
   //for 1,1,2 (nC2 * 2* numberOftwos)
   ans += (one * (one - 1) / 2) * two * 2;
   //for 1,2,2 (nC2 * numberOfones)
   ans += (two * (two - 1) / 2) * one;
   //for 1,1,x (nC2 * (total-ones))
   ans += (one * (one - 1) / 2) * (extra + three);
   // for 1,2,3 
   ans += one * two * three;

   cout << ans << endl;
}