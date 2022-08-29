#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           10000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int phi[MX], ans[MX];

void ETF()
{
    for (int i = 1; i < MX; i++)
        phi[i] = i;
    for (int i = 2; i < MX; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MX; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
void Work()
{
    double mnQuot = 1e10;
    int curNum = 0;
    for (int i = 2; i < MX; i++) {
        int x = i, y = phi[i], c1[10] = {}, c2[10] = {};
        bool ok = 1;

        while (x) c1[x % 10]++, x /= 10;
        while (y) c2[y % 10]++, y /= 10;

        rep(i, 0, 9) {
            if (c1[i] != c2[i]) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            ans[i] = curNum;
            continue;
        }
        double cur = (1.0 * i) / (phi[i] * 1.0);
        if (cur <= mnQuot) {
            mnQuot = cur;
            curNum = i;
        }
        ans[i] = curNum;
    }
}
void Solve(int tc)
{
    int M;
    cin >> M;

    if (ans[M - 1]) cout << ans[M - 1] << "\n";
    else cout << "No solution.\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ETF();
    Work();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}