#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      1000001
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

int cnt[MX + 5], divisors[MX + 5];
bool is_prime[MX + 5];

inline void sieve()
{
   for (int i = 2; i < MX; i += 2)
      divisors[i] = 2;
   for (int i = 3; i < MX; i += 2)
      if (!divisors[i])
         for (int j = i; j < MX; j += i)
            if (!divisors[j])
               divisors[j] = i;
   for (int i = 1; i < MX; i++) {
      if (!divisors[i]) {
         divisors[i] = i;
         cnt[i]++;
      }
      else
         cnt[divisors[i]]++;
   }
}
int main()
{
   IOS
   sieve();
   cin >> t;

   W(t)
   {
      cin >> n;
      cout << cnt[n] << endl;
   }
}