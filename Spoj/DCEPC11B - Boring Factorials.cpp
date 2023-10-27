#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         100005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int modInv(int a, int x, int mod)
{
    int res = 1;
    while (x) {
        if (x & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        x >>= 1;
    }
    return res;
}
void Solve(int tc)
{
    int n, p;

    cin >> n >> p;
    if (n >= p) cout << "0\n";
    else {
        /* Wilson theorem (if and only if p is a prime number):
           1. (p-1)! ≅ -1 (mod p)
           2. (p-1)! ≅ p-1 (mod p)
        */

        int ans = p - 1;
        for (int i = n + 1; i < p; i++) {
            ans = (ans * modInv(i, p - 2, p)) % p;
        }
        cout << ans << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

}