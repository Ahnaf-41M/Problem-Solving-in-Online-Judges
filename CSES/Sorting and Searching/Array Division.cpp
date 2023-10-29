#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         200005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int n, k, curAns;
int ar[MX];
bool valid(int mxSum)
{
    int subSum = 0, cnt = 1;
    curAns = 0;
    for (int i = 1; i <= n; i++) {
        if (subSum + ar[i] <= mxSum) {
            subSum += ar[i];
        }
        else {
            subSum = ar[i];
            cnt++;
        }
        curAns = max(curAns, subSum);
    }
    return (cnt <= k);
}
void Solve(int tc)
{
    cin >> n >> k;

    int low = 0, high = 0, ans = 1e18;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        high += ar[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (valid(mid)) {
            ans = min(ans, curAns);
            high = mid - 1;
        }
        else low = mid + 1;
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