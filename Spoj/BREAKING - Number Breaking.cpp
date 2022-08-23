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

int spf[MX];

void Sieve()
{
    for (int i = 2; i < MX; i++)
        spf[i] = i;
    for (int i = 2; i < MX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MX; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
void Solve(int tc)
{
    int n;
    cin >> n;
    cout << "Case " << tc << ": ";
    while (n > 1) {
        int d = spf[n];
        cout << d << " ";
        while (n % d == 0)
            n /= d;
    }
    cout << "\n";
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