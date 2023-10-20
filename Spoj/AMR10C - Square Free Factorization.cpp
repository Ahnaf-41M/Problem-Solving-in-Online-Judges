#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         1000005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int spf[MX];

void Sieve()
{
    for (int i = 2; i < MX; i++) {
        if (!spf[i]) {
            for (int j = i; j < MX; j += i) {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}
void Solve(int tc)
{
    int n;
    vector<PII> v;
    cin >> n;

    while (n > 1) {
        int d = spf[n], cnt = 0;
        while (n % d == 0)
            n /= d, cnt++;
        v.pb({cnt, d});
    }
    sort(all(v));

    int ans = 0, cur = 0;
    for (auto it : v) {
        int req = it.ff - cur;
        ans += req;
        cur += req;
    }
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

}