#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           100005
#define  N            1024
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int cnt[MX];
void Solve(int tc)
{
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, mask = 0;
        cin >> x;

        while (x) {
            int dig = x % 10;
            mask |= (1 << dig);
            x /= 10;
        }
        cnt[mask]++;
    }
    for (int i = 1; i < N; i++) {
        ans += (cnt[i] * (cnt[i] - 1) / 2); //pairs of numbers having same digits (i.e. 1270 and 7021)
        for (int j = i + 1; j < N; j++) {
            if (i & j) //digits common between i and j mask
                ans += cnt[i] * cnt[j];
        }
    }
    cout << ans << "\n";
    for (int i = 1; i < N; i++) cnt[i] = 0;
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
/*
  - Which number is on in a number will be maintained by a state called mask.
  - Every state of 1024 sets will specify which digits are remaining on here.For 12, our state
    2^1 + 2^2 = 6 [0 0 0 0 0 1 1 0] states for 10 numbers, where 1 and 2 positions have one which in
    turn makes sense to us this state contains 1 and 2 digits.
*/