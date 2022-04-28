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

void Solve(int tc)
{
    int n;
    set<int> unq;
    multiset<int> tot;

    cin >> n;
    while (n--) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "insert") {
            unq.insert(x);
            tot.insert(x);
        }
        else if (unq.find(x) != unq.end()) {
            tot.erase(tot.find(x));
            if (tot.find(x) == tot.end()) unq.erase(x);
        }

        if (unq.size() > 1 && tot.size() != unq.size()) cout << "both\n";
        else if (unq.size() > 1) cout << "hetero\n";
        else if (tot.size() != unq.size()) cout << "homo\n";
        else cout << "neither\n";
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