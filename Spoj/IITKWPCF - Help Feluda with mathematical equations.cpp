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

int ok[MX];
vector<int> v, ans;
vector<PII> pfactors;
map<int, int> isPrime;
void Sieve()
{
    for (int i = 2; i < MX; i++) {
        if (!ok[i]) {
            for (int j = i * i; j < MX; j += i)
                ok[j] = 1;
        }
    }
    for (int i = 2; i < MX; i++) if (!ok[i]) v.pb(i);
}
void generateDivisors(int curIndex, int curDivisor)
{
    if (curIndex == pfactors.size()) {
        if (!isPrime[curDivisor]) ans.pb(curDivisor);
        return;
    }

    for (int i = 0; i <= pfactors[curIndex].ff; i++) {
        generateDivisors(curIndex + 1, curDivisor);
        curDivisor *= pfactors[curIndex].ss;
    }
}
void Clear()
{
    ans.clear();
    pfactors.clear();
    isPrime.clear();
}
void Solve(int tc)
{
    int n;
    cin >> n;

    if (n == 0) cout << "0 0\n";
    else if ((n & 1)) cout << "0\n";
    else {
        int m = n / 2;
        for (int d : v) {
            if (d * d > m) break;
            int cnt = 0;
            while (m % d == 0)
                m /= d, cnt++;
            if (cnt) {
                pfactors.pb({cnt, d});
                isPrime[d] = 1;
            }
        }
        if (m > 1) {
            pfactors.pb({1, m});
            isPrime[m] = 1;
        }
        generateDivisors(0, 1);
        sort(all(ans));
        cout << ans.size() << " ";
        for (int x : ans) cout << x << " ";
        cout << "\n";

        Clear();
    }
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