#include <bits/stdc++.h>
#include <ext/rope>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))

#define count_one(a) __builtin_popcount(a) // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i) __builtin_parity(i)      //even parity 0 and odd parity 1
#define blz(a) __builtin_clz(a)            //Returns the number of leading zeroes in a number(a)
#define btz(a) __builtin_ctz(a)            //Returns the number of trailing zeroes in a number(a)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))

#define pb push_back
#define PI M_PI
#define endl "\n"
#define sc scanf
#define pf printf

#define ll long long
#define ull unsigned long long

#define W(t) while (t--)
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(a, b) for (int i = a; i <= b; i++)
#define rep3(a, b, c) for (int i = a; i <= b; i += c)
#define irep(a, b, c) for (int i = b; i >= a; i -= c)
#define repit(it, type) for (it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
#define mx 100005
ll dp1[mx], dp2[mx], a[mx], b[mx];

int main()
{
    IOS

        ll n,
        l, i, r, j, type, query;

    cin >> n >> query;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (i = 2; i <= n; i += 2)
    {
        swap(a[i], b[i]);
    }
    for (i = 1; i <= n; i++)
    {
        dp1[i] = dp1[i - 1] + a[i];
        dp2[i] = dp2[i - 1] + b[i];
    }
    W(query)
    {
        cin >> type >> l >> r;
        assert(l<=r);
        if (type == 1)
        {
            if (l & 1)
                cout << dp1[r] - dp1[l - 1] << endl;
            else
                cout << dp2[r] - dp2[l - 1] << endl;
        }
        else
        {
            if (l & 1)
                cout << dp2[r] - dp2[l - 1] << endl;
            else
                cout << dp1[r] - dp1[l - 1] << endl;
        }
    }
}