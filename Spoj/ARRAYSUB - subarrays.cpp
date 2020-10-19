#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, mx;
    vector<int> v;

    cin >> n;

    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    for (i = 0; i < n; i++)
    {
        mx = -1;
        for (int j = i; j < i + k && i + k <= n; j++)
            mx = max(mx, a[j]);
        if (mx != -1)
            v.push_back(mx);
    }
    for (i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}