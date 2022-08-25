/* [phi(1) * phi(1)] + [2 * phi(1) * phi(2)] + [2 * phi(1) * phi(3)] + [2 * phi(1) * phi(4)] + ....
                           [phi(2) * phi(2)] + [2 * phi(2) * phi(3)] + [2 * phi(2) * phi(4)] + ...
                                                   [phi(3) * phi(3)] + [2 * phi(3) * phi(4)] + ...
*/
#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           10005
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
            for (int j = i; j < MX; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}
void Work()
{
    int cur_totient_sum = 0;
    for (int i = 1; i < MX; i++) {
        ans[i] += ans[i - 1];
        ans[i] += phi[i] * phi[i] + (2 * cur_totient_sum * phi[i]);
        cur_totient_sum += phi[i];
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

    ETF();
    Work();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}