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

int phi[MX], primeCnt[MX], fact[MX], F[MX], G[MX];
int mod = 1e9 + 7;

void ETF_Sieve()
{
    for (int i = 1; i < MX; i++)
        phi[i] = i;
    for (int i = 2; i < MX; i++) {
        if (phi[i] == i) {
            primeCnt[i] = 1;
            for (int j = i; j < MX; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 1; i < MX; i++) {
        primeCnt[i] += primeCnt[i - 1];
        F[i] = primeCnt[i] - phi[i];
        F[i] = (F[i] < 0 ? 0 : F[i]);
    }
}
int BigMod(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = (res * a) % mod;
        a *= a;
        p >>= 1;
    }
    return res;
}
void Work()
{
    fact[0] = 1;
    for (int i = 1; i < MX; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    for (int i = 0; i < MX; i++) {
        G[i] = BigMod(phi[i], fact[F[i]]);
    }

}
void Solve(int tc)
{
    int n;
    cin >> n;
    cout << G[n] << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ETF_Sieve();
    Work();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}