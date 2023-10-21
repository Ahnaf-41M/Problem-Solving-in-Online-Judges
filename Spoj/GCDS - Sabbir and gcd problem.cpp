#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         10000005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int spf[MX], cnt[MX];
vector<int> v;
void Sieve()
{
    for (int i = 2; i < MX; i++) {
        if (!spf[i]) {
            v.pb(i);
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
    vector<int> pFactors;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x > 1) {
            int d = spf[x];
            cnt[d]++;
            if (cnt[d] == 1) pFactors.pb(d);
            while (x % d == 0)
                x /= d;
        }
    }
    int i = 0;
    while (cnt[v[i]]) i++;
    cout << v[i] << "\n";

    for (int d : pFactors) cnt[d] = 0;
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