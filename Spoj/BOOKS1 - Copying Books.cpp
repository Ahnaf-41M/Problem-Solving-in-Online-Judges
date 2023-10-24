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

int n, k, mnLim, mxLim;
int ar[505];

bool Ok(int mid)
{
    int curSum = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (ar[i] > mid) {
            cnt = 1e10;
            break;
        }
        if (curSum + ar[i] > mid) {
            curSum = 0;
            cnt++;
        }
        curSum += ar[i];
    }
    return cnt <= k;
}
void Solve(int tc)
{
    mxLim = 0;
    mnLim = 1e10;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        mnLim = min(mnLim, ar[i]);
        mxLim += ar[i];
    }

    int low = mnLim, high = mxLim;
    while (low < high) {
        int mid = (low + high) / 2;
        if (Ok(mid)) {
            mxLim = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    // cout << mxLim << "\n";

    vector<int> ans;
    int curSum = 0, cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (curSum + ar[i] > mxLim || i == k - cnt - 1) {
            curSum = 0;
            ans.pb(-1);
            cnt++;
        }
        curSum += ar[i];
        ans.pb(ar[i]);
    }
    reverse(all(ans));
    for (int x : ans) {
        if (x == -1) cout << "/ ";
        else cout << x << " ";
    }
    cout << "\n";

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