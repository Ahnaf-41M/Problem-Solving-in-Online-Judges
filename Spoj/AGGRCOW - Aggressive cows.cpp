#include <bits/stdc++.h>
using namespace std;

int n, c, i;
vector<int> v(100005);
bool is_possible(int value)
{
    //for checking if we can get the value at least c times 
    int prev = v[0], cow = 1;

    for (i = 0; i < n; i++)
    {
        if (v[i] - prev >= value)
        {
            cow++;
            if (cow == c)
                return true;
            prev = v[i];
        }
    }
    return false;
}
int bin_search()
{
    int left, right, mid;
    left = 0;
    right = v[n - 1];

    while (left < right)
    {
        mid = (left + right) / 2;

        if (is_possible(mid))
        {
            left = mid + 1;
            //cout << "left: " << left << endl;
        }
        else
        {
            right = mid;
           // cout << "right: " << right << endl;
        }
    }
    return (left - 1);
}
int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        for (i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.begin() + n);
        cout << bin_search() << endl;
    }
}