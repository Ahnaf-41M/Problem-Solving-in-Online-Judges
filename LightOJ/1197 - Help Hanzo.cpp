#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      1000005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
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

bitset < MX + 5 > is_prime;
ll pre_sum[MX + 5];
vector<ll> primes;
inline void sieve()
{
   is_prime[2] = 1;
   for (int i = 3; i <= MX; i += 2)
      is_prime[i] = 1;
   for (int i = 3; i <= sqrt(MX); i += 2)
      if (is_prime[i])
         for (int j = i * 2; j <= MX; j += i)
            is_prime[j] = 0;
   primes.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (is_prime[i])
         primes.pb(i);
}
ll Segmented_Sieve(ll L, ll R)
{
   ll N = R - L + 1;
   bool is[N];
   memset(is, true, sizeof(is));

   if (L == 1)
      is[0] = false;
   for (ll i = 0; primes[i]*primes[i] <= R; i++) {
      ll cur_prm = primes[i];
      ll base = cur_prm * cur_prm;

      if (base < L)
         base = ((L - 1 + cur_prm) / cur_prm) * cur_prm;

      for (ll j = base; j <= R; j += cur_prm)
         is[j - L] = false;
   }
   ll ans = 0;
   for (ll j = 0; j < N; j++)
      if (is[j])
         ans++;
   return ans;
}
int main()
{
   sieve();
   ll t, k, i, a, b;
   scanf("%lld", &t);

   rep(k, 1, t + 1)
   {
      scanf("%lld%lld", &a, &b);
      printf("Case %lld: %lld\n", k, Segmented_Sieve(a, b));
   }
}