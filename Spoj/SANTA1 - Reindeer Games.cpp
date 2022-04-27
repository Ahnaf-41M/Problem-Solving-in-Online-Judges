#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int M, ans = 0;
set<PII> S;
set<PII>::iterator it1, it2;
map<string, PII> mp;

void ADD(int prod, string name)
{
    it1 = S.lower_bound(mp[name]);
    it2 = it1;
    if (it1 == S.end()) {
        it1--;
        ans += (it1->ss * prod);
    }
    else {
        if (it2 != S.begin()) {
            it2--;
            ans -= (it1->ss * it2->ss);
            ans += (it2->ss * prod);
            // cout << name << " " << it1->ss << " " << it2->ss << "\n";
        }
        ans += (it1->ss * prod);
        // cout << name << " " << it1->ss << " " << it2->ss << "\n";
    }
    S.insert(mp[name]);
}
void REMOVE(string name)
{
    it1 = S.upper_bound(mp[name]);
    it2 = S.lower_bound(mp[name]);
    if (it1 != S.end()) {
        ans -= (it1->ss * mp[name].ss);
    }
    if (it2 != S.begin()) {
        it2--;
        ans -= (it2->ss * mp[name].ss);
        if (it1 != S.end())
            ans += (it1->ss * it2->ss);
    }
    S.erase(mp[name]);
    mp.erase(name);
}
void Solve(int tc)
{
    cin >> M;
    while (M--) {
        char ch;
        string name;
        int sen, prod;

        cin >> ch >> name;

        if (ch == 'A') {
            cin >> sen >> prod;
            mp[name] = {sen, prod};
            if (S.empty()) S.insert(mp[name]);
            else ADD(prod, name);
        }
        else if (mp.find(name) != mp.end()) REMOVE(name);
        cout << ans << "\n";
    }
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

    return 0;
}