#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000000
ll a[mx], pre_sum1[mx];
ll b[mx], pre_sum2[mx];

int main()
{
    ll n, m, i, g, h;

    while (cin >> n && n)
    {
        map<ll, ll> ind1, ind2;
        vector<ll> v;

        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            ind1[a[i]] = i;
        }
        cin >> m;

        for (i = 1; i <= m; i++)
        {
            cin >> b[i];
            ind2[b[i]] = i;
        }
        for (i = 1; i <= n; i++)
        {
            if (i == 1)
                pre_sum1[i] = a[i];
            else
                pre_sum1[i] = pre_sum1[i - 1] + a[i];
        }
        for (i = 1; i <= m; i++)
        {
            if (i == 1)
                pre_sum2[i] = b[i];
            else
                pre_sum2[i] = pre_sum2[i - 1] + b[i];
        }
        for (i = 1; i <= n; i++)
        {
            if (binary_search(b + 1, b + m + 1, a[i]))
            {
                v.push_back(a[i]);
            }
        }
        ll ans = 0;
        if (!v.empty())
            ans = max(pre_sum1[ind1[v[0]]], pre_sum2[ind2[v[0]]]);
        for (i = 1; i < v.size(); i++)
        {
            g = pre_sum1[ind1[v[i]]] - pre_sum1[ind1[v[i - 1]]];
            h = pre_sum2[ind2[v[i]]] - pre_sum2[ind2[v[i - 1]]];
            ans += max(g, h);
        }
        if (!v.empty())
        {
            g = (pre_sum1[n] - pre_sum1[ind1[v[v.size() - 1]]]);
            h = (pre_sum2[m] - pre_sum2[ind2[v[v.size() - 1]]]);
            ans += max(g, h);
        }
        else
        {
            ans = max(pre_sum1[n],pre_sum2[m]);
        }
        
        cout << ans << endl;
    }
}