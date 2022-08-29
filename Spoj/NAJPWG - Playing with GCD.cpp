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

int phi[MX], pref[MX];

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
    for (int i = 2; i < MX; i++) {
        pref[i] = (i - phi[i]);
        pref[i] += pref[i - 1];
    }
}
void Solve(int tc)
{
    int n;
    cin >> n;
    cout << "Case " << tc << ": " << pref[n] << "\n";
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