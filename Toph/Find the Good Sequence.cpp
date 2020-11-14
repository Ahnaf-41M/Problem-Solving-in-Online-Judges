#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      100005
#define  inf     INT_MAX
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  all(v)          v.begin(),v.end()
#define  clr(a,x)        memset(a,x,sizeof(a))
#define  rep(i,a,b)      for(i = a; i <= b; i++)
#define  irep(i,b,a)     for(i = b; i >= a; i--)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif

   IOS
   int n, i;
   stack<int> stk;

   cin >> n;
   int a[n];

   rep(i, 0, n - 1) cin >> a[i];

   rep(i, 0, n - 1) {
      if (stk.empty())
         stk.push(a[i]);
      else {
         if (a[i] - stk.top() >= 2)
            stk.push(a[i]);
         else {
            while (!stk.empty())
            {
               if (stk.size() == 1) {
                  cout << 0 << endl;
                  stk.pop();
               }
               else {
                  cout << stk.size() << endl;
                  stk.pop();
               }
            }
            stk.push(a[i]);
         }
      }
   }
   while (!stk.empty())
   {
      if (stk.size() == 1) {
         cout << 0 << endl;
         stk.pop();
      }
      else {
         cout << stk.size() << endl;
         stk.pop();
      }
   }
}