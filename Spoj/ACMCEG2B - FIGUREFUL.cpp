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
    int n, t;
    map<PII, string> mp;

    cin >> n;
    while (n--) {
        int code1, code2;
        string name;
        cin >> code1 >> code2 >> name;
        mp[ {code1, code2}] = name;
    }

    cin >> t;
    while (t--) {
        int code1, code2;
        cin >> code1 >> code2;
        cout << mp[ {code1, code2}] << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}