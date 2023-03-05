#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           3262278
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int OK[MX];
vector<int> v;

void Sieve()
{
    for(int i = 3; i < MX; i += 2)
        OK[i] = 1;
    v.pb(2);
    for(int i = 3 ; i < MX; i += 2) {
        if(OK[i]) {
            v.pb(i);
            for(int j = i*i; j < MX; j += i)
                OK[j] = 0;
        }
    }
}
void Solve(int tc)
{
    int n;
    cin >> n;

    if(n == 1) cout << "ANNE\n";
    else {
        vector<PII> factors;
        for(int x : v) {
            if(x*x > n) break;
            if(n % x == 0) {
                int cnt=0;
                while(n % x == 0)
                    n /= x, cnt++;
                factors.pb({x,cnt});
            }
        }
        if(n > 1) factors.pb({n,1});

        if(factors.size() == 1) {
            if(factors[0].ss == 2) cout << "MARIAN\n";
            else cout << "ANNE\n";
        } else if(factors.size() == 2) {
            if(factors[0].ss == 1 && factors[1].ss == 1) cout << "MARIAN\n";
            else cout << "ANNE\n";
        } else cout << "ANNE\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
    // cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}
