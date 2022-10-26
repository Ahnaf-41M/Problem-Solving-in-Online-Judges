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

vector<int> Pref_Func(string s)
{
    int len = s.size();
    vector<int> v(len);

    for (int i = 1; i < len; i++) {
        int j = v[i - 1];
        while (j > 0 && s[i] != s[j])
            j = v[j - 1];
        if (s[i] == s[j]) j++;
        v[i] = j;
    }
    return v;
}
vector<int> KMP(string txt, string pat)
{
    vector<int> lps = Pref_Func(pat);
    int n = txt.size(), m = pat.size();
    vector<int> ans;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && txt[i] != pat[j])
            j = lps[j - 1];
        if (txt[i] == pat[j]) j++;
        if (j == m) {
            ans.pb(i - j + 2);
            j = lps[j - 1];
        }
    }
    return ans;
}
void Solve(int tc)
{
    string txt, pat;
    vector<int> ans;

    cin >> txt >> pat;

    ans = KMP(txt, pat);

    if (ans.empty()) cout << "Not Found\n\n";
    else {
        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
        cout << "\n\n";
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

    return 0;
}