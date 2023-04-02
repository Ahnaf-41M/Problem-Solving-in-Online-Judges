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

int is_square[MX];
int pref[MX][10];
void Sieve()
{
    for (int i = 4; i < MX; i++) {
        double sq = sqrt(i * 1.0);
        if (ceil(sq) == floor(sq)) {
            for (int j = i; j < MX; j += i) {
                is_square[j] = 1;
            }
        }
    }
    for (int i = 1; i < MX; i++) {
        int x = i;
        for (int j = 0; j < 10; j++)
            pref[i][j] = pref[i - 1][j];
        if (is_square[i]) continue;

        set<int> digits;
        while (x) {
            digits.insert(x % 10);
            x /= 10;
        }
        for (int x : digits) pref[i][x]++;
    }
}
void Solve(int tc)
{
    int l, r, d;
    cin >> l >> r >> d;

    cout << pref[r][d] - pref[l - 1][d] << "\n";
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