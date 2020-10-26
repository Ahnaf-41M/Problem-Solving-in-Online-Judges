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

	int t, n, m, k, i, j;

	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		scanf("%d%d", &n, &m);
		ll a[n];
		rep(i, 0, n) scanf("%lld", &a[i]);
		W(m)
		{
			char type; cin >> type;
			if (type == 'S') {
				ll D; scanf("%lld", &D);
				rep(i, 0, n) a[i] += D;
			}
			else if (type == 'M') {
				ll D; scanf("%lld", &D);
				rep(i, 0, n) a[i] *= D;
			}
			else if (type == 'D') {
				ll K; scanf("%lld", &K);
				rep(i, 0, n) a[i] /= K;
			}
			else if (type == 'R')
				reverse(a, a + n);
			else {
				int Y, Z; scanf("%d%d", &Y, &Z);
				swap(a[Y], a[Z]);
			}
		}
		printf("Case %d:\n", k);
		rep(i, 0, n){
			if(i==0)
				printf("%lld",a[i]);
			else
				printf(" %lld",a[i]);
		}
		printf("\n");
	}
}