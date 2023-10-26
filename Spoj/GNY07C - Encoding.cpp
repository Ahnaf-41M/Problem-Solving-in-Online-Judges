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

map<char, string> mp;
map<char, char> nextDir;
bool vis[25][25];
char ans[25][25];
int n, m;

string getVal(char ch)
{
    int n = ch - 'A' + 1;
    string res;

    while (n) {
        if (n & 1) res.pb('1');
        else res.pb('0');
        n >>= 1;
    }
    while (res.size() < 5) res.pb('0');
    reverse(all(res));
    return res;
}
void pre_process()
{
    mp[' '] = "00000";
    for (char ch = 'A'; ch <= 'Z'; ch++)
        mp[ch] = getVal(ch);
    nextDir['R'] = 'D';
    nextDir['D'] = 'L';
    nextDir['L'] = 'U';
    nextDir['U'] = 'R';
}
bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}
void Solve(int tc)
{
    string s, s2;
    string res;

    cin >> n >> m;
    getline(cin, s);

    for (int i = 1; i < s.size(); i++)
        for (char ch : mp[s[i]])
            s2.pb(ch);
    s = s2;
    // cout << s << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = '0';
            vis[i][j] = 0;
        }
    }

    int i = 0, j = -1, cnt = n * m, k = 0;
    char curD = 'R';
    while (k < s.size()) {
        if (curD == 'R') {
            if (valid(i, j + 1))
                j++;
            else {
                curD = nextDir[curD];
                i++;
            }
        }
        else if (curD == 'D') {
            if (valid(i + 1, j))
                i++;
            else {
                curD = nextDir[curD];
                j--;
            }
        }
        else if (curD == 'L') {
            if (valid(i, j - 1))
                j--;
            else {
                curD = nextDir[curD];
                i--;
            }
        }
        else if (curD == 'U') {
            if (valid(i - 1, j))
                i--;
            else {
                curD = nextDir[curD];
                j++;
            }
        }
        vis[i][j] = 1;
        ans[i][j] = s[k];
        // cout << i << " " << j << "\n";
        k++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << ans[i][j];
            res.pb(ans[i][j]);
        }
        // cout << "\n";
    }
    cout << tc << " " << res << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre_process();
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

}