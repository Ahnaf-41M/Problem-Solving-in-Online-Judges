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

bool prime[MX];
vector<int> v;

void Sieve()
{
    for (int i = 3; i < MX; i += 2)
        prime[i] = 1;
    for (int i = 3; i * i < MX; i += 2)
        if (prime[i])
            for (int j = i * i; j < MX; j += i)
                prime[j] = 0;
    v.pb(2);
    for (int i = 3; i < MX; i += 2)
        if (prime[i])
            v.pb(i);
}
vector<int> Factorize(int n)
{
    vector<int> ans;
    if (n < 0) ans.pb(-1);
    n = abs(n);
    for (int x : v) {
        if (x * x > n) break;
        while (n % x == 0)
            n /= x, ans.pb(x);
    }
    if (n > 1) ans.pb(n);
    return ans;
}
void Solve(int tc)
{
    int n;
    while (cin >> n && n) {
        vector<int> ans = Factorize(n);

        cout << n << " = " << ans[0];
        for (int i = 1; i < (int)ans.size(); i++)
            cout << " x " << ans[i];
        cout << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
    //cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}