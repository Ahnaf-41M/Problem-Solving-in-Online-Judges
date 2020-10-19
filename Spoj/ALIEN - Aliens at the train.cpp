#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, cnt = 0, sum = 0, n, t, m;

    scanf("%d", &t);

    while (t--)
    {
        int cnt = 0, total = 0, left, right, people = 0, stations = 0;
        scanf("%d %d", &n, &m);
        int a[n + 1];
        for (i = 1; i <= n; i++)
            cin >> a[i];

        for (left = 1, right = 1; right <= n; right++)
        {
            total += a[right];
            while (total > m)
                total -= a[left++];
            cnt = right - (left - 1);
            if (cnt > stations)
            {
                people = total;
                stations = cnt;
            }
            else if (cnt == stations)
                people = min(people, total);
        }
        printf("%d %d\n", people, stations);
    }
}