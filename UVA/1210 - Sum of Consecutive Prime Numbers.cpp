#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      10000
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

bool is_prime[10005];
vector<int> primes;
int freq[MX + 5];

void sieve()
{
   for (int i = 3; i <= MX; i += 2)
      is_prime[i] = true;
   for (int i = 3; i <= sqrt(MX); i += 2)
      if (is_prime[i])
         for (int j = i * i; j <= MX; j += i)
            is_prime[j] = false;
   primes.pb(2);

   for (int i = 3; i <= MX; i += 2)
      if (is_prime[i])
         primes.pb(i);
}
void pre_process()
{
   for (int i = 0; i < primes.size(); i++) {
      int sum = primes[i];
      freq[sum]++;
      for (int j = i - 1; j >= 0; j--) {
         sum += primes[j];
         if (sum > MX)
            break;
         freq[sum]++;
      }
   }
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   sieve();
   pre_process();
   int n;

   while (scanf("%d", &n))
   {
      if (n == 0)
         break;
      printf("%d\n", freq[n]);
   }
}