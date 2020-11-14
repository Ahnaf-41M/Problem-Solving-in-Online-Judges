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
   IOS
   int n, k, i, j;
   unordered_map<char, int> freq;
   string s;
   char req = '0';

   cin >> n >> k >> s;
   rep(i, 0, n - 1) {
      freq[s[i]]++;
   }
   for (auto it : freq) {
      // cout << it.ff<<" "<<it.ss<<endl;
      if (it.ss == k)
         if (req < it.ff)
            req = it.ff;
   }
   bool done = false;

   rep(i, 0, n - 1) {
      if (s[i] == req && k > 1) {
         if (!done && s[i] < s[i + 1]) {
            cout << s[i];
            done = true;
         }
         else
            k--;
      }
      else
         cout << s[i];
   }
}