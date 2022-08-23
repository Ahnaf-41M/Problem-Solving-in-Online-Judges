#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           11000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int spf[MX];
vector<int> ans;
void Sieve()
{
    ans.pb(0);
    for (int i = 2; i < MX; i++) {
        if (!spf[i]) {
            for (int j = i; j < MX; j += i) {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
    for (int i = 2; i < MX; i++) {
        int d1 = spf[i];
        int d2 = spf[(i / d1)];
        if (d1 != d2 && d1 * d2 == i)
            ans.pb(i);
    }
}
void Solve(int tc)
{
    int k;
    cin >> k;
    cout << ans[k] << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    // cout << ans.size() << "\n";
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}