#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int OK[MX], ans[MX];

int Check(int x)
{
    int flg = 1, cur = 0, cnt10 = 0, y = x;
    while (x) {
        int term = x % 10;
        for (int i = 1; i <= cnt10; i++) term *= 10;
        cur = cur + term;
        if (term == 0 || (!OK[cur] && cur)) {
            flg = 0;
            break;
        }
        // if (y == 632647)
        //     cout << cur << " ";
        x /= 10;
        cnt10++;
    }
    return flg;
}
void Sieve()
{
    OK[2] = 1;
    for (int i = 3; i < MX; i += 2)
        OK[i] = 1;
    for (int i = 3; i * i < MX; i += 2)
        if (OK[i])
            for (int j = i * i; j < MX; j += i)
                OK[j] = 0;
    ans[2] = 1;
    for (int i = 3; i < MX; i++) {
        if (OK[i]) ans[i] = Check(i);
        ans[i] += ans[i - 1];
    }
}
void Solve(int tc)
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
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

    return 0;
}