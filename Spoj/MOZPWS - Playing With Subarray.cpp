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

int ar[MX], segTree[4 * MX], mnAr[MX];
int n, k;

void init(int node, int b, int e)
{
    if (b == e) {
        segTree[node] = mnAr[b];
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);
    segTree[node] = max(segTree[left], segTree[right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return -3e18;
    if (b >= i && e <= j)
        return segTree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);

    return max(p1, p2);
}
void Solve(int tc)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        mnAr[i] = -3e18;
    }

    multiset<int> s;

    for (int i = 1; i <= n; i++) {
        s.insert(ar[i]);
        if (i >= k) {
            mnAr[i] = (*s.begin());
            s.erase(s.lower_bound(ar[i - k + 1]));
        }
    }

    init(1, 1, n);
    cout << "Case " << tc << ":\n";
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 < k) cout << "Impossible\n";
        else cout << query(1, 1, n, l + k - 1, r) << "\n";
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