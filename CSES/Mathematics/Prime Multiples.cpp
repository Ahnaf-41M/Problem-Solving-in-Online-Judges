#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int n, k, ans;
vector<int> primes;

void Inclusion_Exclusion()
{
    for (int i = 1; i < (1 << k); i++) {
        int cur = 0, cnt = 0, curDiv = 1;
        int m = n;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                curDiv *= primes[j];
                cnt++;
                m /= primes[j];
            }
        }
        if (!m) continue;
        if (cnt & 1) ans += (n / curDiv);
        else ans -= (n / curDiv);
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        primes.pb(x);
    }
    Inclusion_Exclusion();

    return 0;
}