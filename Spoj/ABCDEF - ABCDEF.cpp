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

void Solve(int tc)
{
    int n, ans = 0;
    map<int, int> mp;
    cin >> n;

    int ar[n];
    for (int &x : ar) cin >> x;

    for (int a : ar) {
        for (int b : ar) {
            for (int c : ar) {
                mp[a * b + c]++;
            }
        }
    }
    for (int d : ar) {
        if (!d) continue;
        for (int e : ar) {
            for (int f : ar) {
                ans += mp[d * (f + e)];
            }
        }
    }

    cout << ans << "\n";

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

}