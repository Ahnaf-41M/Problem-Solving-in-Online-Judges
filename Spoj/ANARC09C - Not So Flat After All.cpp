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
int cnt_a[MX], cnt_b[MX];
vector<int> v;
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
void factorization(int x, int cnt[])
{
    while (x > 1) {
        int d = spf[x];
        if (!cnt_a[d] && !cnt_b[d]) v.pb(d);
        while (x % d == 0)
            x /= d, cnt[d]++;
    }
}
void Solve(int tc)
{
    int a, b;
    int i = 1;
    while (cin >> a >> b) {
        if (!a && !b) break;
        factorization(a, cnt_a);
        factorization(b, cnt_b);

        int dis = 0;
        for (int d : v) {
            dis += abs(cnt_a[d] - cnt_b[d]);
            cnt_a[d] = cnt_b[d] = 0;
        }

        cout << (i++) << ". " << v.size() << ":" << dis << "\n";
        v.clear();
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

}