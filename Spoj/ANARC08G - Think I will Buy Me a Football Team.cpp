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
    int n, i = 1;
    while (cin >> n) {
        if (!n) break;
        int ar[n][n], b[n];
        int tot = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            b[i] = 0;
            for (int j = 0; j < n; j++) {
                cin >> ar[i][j];
                tot += ar[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i] -= ar[i][j];
                b[j] += ar[i][j];
            }
        }
        for (int x : b) if (x > 0) ans += x;
        cout << (i++) << ". " << tot << " " << ans << "\n";
    }
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