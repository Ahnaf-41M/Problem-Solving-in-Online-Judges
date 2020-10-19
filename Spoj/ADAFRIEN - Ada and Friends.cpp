#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t, frnd, cost, ans = 0, len;

    while (scanf("%lld%lld", &t, &frnd) != EOF)
    {
        ans = 0;ll k = 0;
        map<string, ll> mp;
        map<string, ll>::iterator it;
        vector<ll> v;
        string name;
        while (t--)
        {
            cin >> name >> cost;
            mp[name] += cost;
        }
        for (it = mp.begin(); it != mp.end(); it++)
            v.push_back(it->second);

        sort(v.begin(), v.end(), greater<ll>());
        len = v.size();

        k = frnd;

        for (int i = 0; i < v.size(); i++)
        {
            if (k > 0)
            {
                ans += v[i];
                k--;
            }
        }

        cout << ans << endl;
    }
}