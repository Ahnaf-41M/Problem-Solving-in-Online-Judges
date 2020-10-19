#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ll sum = 0, ans = 0, n, m, i, end = 1, start = 1;

    scanf("%lld %lld", &n, &m);

    ll a[n + 1];

    for (i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    while (end <= n)
    {
        //adding values till less than m
        while (sum <= m && end <= n)
        {    
            sum += a[end];
            end++;
        }
        ans = max(sum-a[end-1],ans);
        
        //subtracting values till greater than m
        while (sum > m && start <= n)
        {
            sum -= a[start];
            start++;
        }
        ans = max(ans,sum);
        
    }
    printf("%lld\n", ans);
}
