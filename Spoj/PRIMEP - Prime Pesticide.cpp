
#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int spf[MX];
vector<PII> divs[MX];
const int inf = 1e18;
void Sieve()
{
    for(int i = 2; i < MX; i++) spf[i] = i;
    for(int i = 2; i < MX; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j < MX; j+=i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
void Solve(int tc)
{
    int n, q;
    cin >> n >> q;
    int ar[n + 1];

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ar[i] = x;
        while(x > 1) {
            int d = spf[x], d2 = 1;
            if(divs[d].empty()) divs[d].pb({0,0});

            while(x % d == 0)
                x /= d, d2 *= d;
            divs[d].pb({i, divs[d].back().ss + (ar[i] - ar[i]/d2)});
        }
    }

    while(q--) {
        int L,R,p, ans = 0;
        cin >> L >> R >> p;

        PII x1 = {L,0}, x2 = {R,inf};
        int lb = lower_bound(all(divs[p]),x1) - divs[p].begin();
        int up = upper_bound(all(divs[p]),x2) - divs[p].begin();
        up--;

//        cout << lb <<" "<<up<<'\n';
        if(lb <= up) ans += divs[p][up].ss - divs[p][lb-1].ss;
        cout << ans << '\n';
    }

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
//    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}
