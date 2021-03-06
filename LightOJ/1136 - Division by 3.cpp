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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*A number is divisible by 3 if the sum if it's digits are
	  divisible by 3.
	  According to the question: n  --  actual number
	                             1  --  1      sum is -> 1
	                             2  --  12     sum is -> 3
	                             3  --  123    sum is -> 6
	                             4  --  1234   sum is -> 10
	                             5  --  12345  sum is -> 15
	                             5  --  123456 sum is -> 21

	  So for any value of n sum of it's actual values digits are
	  n*(n+1)/2. Now if we observe, for every three actual number
	  there are 2 numbers that are divisible by 3. We just need 
	  to find out numbers from 1 to a-1 and numbers from 1 to b
	  that are divisble by 3. And just print their absolute 
	  difference.1 to a-1 because we need to include a.
	*/
	int t, k;
	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		ll a, b, rem1, rem2, ans = 0;
		scanf("%lld%lld", &a, &b);
		a--;

		rem1 = a % 3;
		rem2 = b % 3;
		a -= rem1; b -= rem2;
		if (rem1 == 2) ans--;
		if (rem2 == 2) ans++;

		ans += ((2.0 * b) / 3.0) - ((2.0 * a) / 3.0);
		printf("Case %d: %lld\n", k, ans);
	}
}