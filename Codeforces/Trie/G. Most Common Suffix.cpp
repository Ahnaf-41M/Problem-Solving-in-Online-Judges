#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[MX];
struct Node
{
    Node *next[26];
    int prefCnt = 0;
};
class Trie {
public:
    int mxLen = 0;
    Node *root;

    Node *getNode() {
        return new Node();
    }
    Trie() {
        root = getNode();
    }

    void insert(string s) {
        Node *cur = root;
        for (char ch : s) {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
                cur->next[val] = getNode();
            cur = cur->next[val];
            cur->prefCnt++;
        }
    }
    void dfs(Node *cur, int x) {
        if (x > mxLen) return;
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (cur->next[i] == NULL) continue;
            dfs(cur->next[i], x + 1);
            res = max(res, cur->next[i]->prefCnt);
        }
        dp[x] = max(res, dp[x]);
    }
};
void Solve(int tc)
{
    Trie T;
    int n, q;
    cin >> n >> q;

    while (n--) {
        string s;
        cin >> s;
        reverse(all(s));
        T.insert(s);
        T.mxLen = max(T.mxLen, (int)s.size());
    }
    T.dfs(T.root, 1);
    while (q--) {
        int x; cin >> x;
        cout << dp[x]  << "\n";
    }
    for (int i = 1; i <= T.mxLen; i++) dp[i] = -1;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}