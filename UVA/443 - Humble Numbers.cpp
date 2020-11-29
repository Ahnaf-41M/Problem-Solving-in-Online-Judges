#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

int primes[] = {2, 3, 5, 7};
vector<int> humble;
int cur_2 = 2, cur_3 = 3, cur_5 = 5, cur_7 = 7;
int k2, k3, k5, k7;
map<int, int> found;

void generate_humble(int m)
{
   if (humble.size() > 5842)
      return;
   if (!found[m])
      humble.pb(m), found[m]++;
   int nxt_mn = min(min(cur_2, cur_3), min(cur_5, cur_7));

   if (nxt_mn == cur_2)
      cur_2 = 2 * humble[++k2];
   else if (nxt_mn == cur_3)
      cur_3 = 3 * humble[++k3];
   else if (nxt_mn == cur_5)
      cur_5 = 5 * humble[++k5];
   else if (nxt_mn == cur_7)
      cur_7 = 7 * humble[++k7];
   generate_humble(nxt_mn);
}
signed main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   humble.pb(1);
   generate_humble(2);
   // cout << humble.size() << endl;

   int n;
   while (cin >> n)
   {
      if (n == 0)
         break;
      string suffix = "";
      if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
         suffix = "th";
      else if (n % 10 == 1)
         suffix = "st";
      else if (n % 10 == 2)
         suffix = "nd";
      else if (n % 10 == 3)
         suffix = "rd";
      else
         suffix = "th";
      cout << "The " << n << suffix << " humble number is " << humble[n - 1] << ".\n";
   }

   return 0;
}