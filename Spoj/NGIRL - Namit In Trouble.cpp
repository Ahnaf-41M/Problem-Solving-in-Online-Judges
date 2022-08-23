#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           110005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int OK[MX];
vector<int> primes, nums, pre;
void Sieve()
{
    OK[2] = 1;
    for (int i = 3; i < MX; i += 2)
        OK[i] = 1;
    for (int i = 3; i * i < MX; i += 2)
        if (OK[i])
            for (int j = i * i; j < MX; j += i)
                OK[j] = 0;
    primes.pb(2);
    for (int i = 3; i < MX; i += 2)
        if (OK[i])
            primes.pb(i);
}
void Work()
{
    nums.pb(0), pre.pb(0);
    for (int x : primes) {
        if (x * x > 1e10) break;
        nums.pb(x * x);
        pre.pb(pre.back() + 1);
    }
}
void Solve(int tc)
{
    int n, k;
    cin >> n >> k;

    int pos1 = upper_bound(all(nums), k) - nums.begin();
    int pos2 = upper_bound(all(nums), n) - nums.begin(); pos2--;

    if (pos1 > pos2) cout << pre[pos2] << " 0\n";
    else cout << pre[pos2] << " " << pre[pos2] - pre[pos1 - 1] << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    Work();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}