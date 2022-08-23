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

int OK[MX], F[MX];
void Sieve()
{
    OK[2] = 1;
    for (int i = 3; i < MX; i += 2)
        OK[i] = 1;
    for (int i = 3; i * i < MX; i += 2)
        if (OK[i])
            for (int j = i * i; j < MX; j += i)
                OK[j] = 0;

    F[0] = 0, F[1] = 1, F[2] = 2;
    for (int i = 3; i < MX; i += 2)
        if (OK[i] == 1)
            F[i] = 0;
}
PII Divisor(int x)
{
    for (int i = sqrt(x); i >= 1; i--) {
        if (x % i == 0) {
            int d1 = i, d2 = x / i;
            // if (d1 != d2)
            return {d1, d2};
        }
    }
}
int func(int x)
{
    if (x <= 2 || F[x] != -1) return F[x];
    PII div = Divisor(x);
    return F[x] = func(div.ff) + func(div.ss);
}
void Solve(int tc)
{
    int x;
    cin >> x;
    cout << func(x) << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(F, F + MX, -1);
    Sieve();
    int T = 1;
    //cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}