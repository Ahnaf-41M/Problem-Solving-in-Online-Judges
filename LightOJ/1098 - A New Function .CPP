/*N = 16
N  : 2  3  4  5  6  7  8
--------------------------------
1  -
2  -
3  -
4  - 2
5  -
6  - 2  3
7  -
8  - 2     4
9  -    3
10 - 2        5
11 -
12 - 2  3  4  5  6
13 -
14 - 2              7
15 -    3     5
16 - 2     4           8
Notice the pattern,
In right edge divisors are 2, 3, 4, 5, 6, 7, 8. It starts at N = 4. Notice
it starts from divisor 2 and ends at 16/2 = 8.Remaining divisors '2' located
underneath the top 2 in a straight line.
Sum += 2+3+4+5+6+7+8
Sum += (8-2)*2. Then, Another divisors are 3, 4, 5. It starts at N = 9. Notice it
starts from divisor '3' and ends at 16/3 = 5. Remaining divisors '3' located underneath
the second top 3 in a straight line.
Sum += 3+4+5
Sum += (5-3)*3. Then, Another divisors are 4. It starts from N = 16.  Notice it
starts from divisor '4' and ends at 16/4 = 4. There is no remaining divisors '4' below.
Sum += 4
Sum += (4-4)*4. Lets calculate sum all of them systematically:
For divisor i = 2, j = 16/2 = 8
Sum = i + i+1 + i+2 + ... + j
    = (1+2+3+ ... +j) - (1+2+3+(i-1))
    = (j*(j+1))/2 - ((i-1)(i))/2
    = (j-i)(j-i+1)/2   <- Skipped few stepsStraight line sum, for divisor i = 2, j = 16/2 = 8
Sum = (j-i)*i . So value of i will be in range [2...sqrt(n)]*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll solve(ll n)
{
    ll i, j;
    ll ret = 0;

    for (i = 2; i <= sqrt(n); i++)
    {
        j = n / i;
        ret += (j + i) * (j - i + 1) / 2;
        ret += (j - i) * i;
    }
    return ret;
}
int main()

{
    ll t, sum = 0, i, x, j, k;

    scanf("%lld", &t);

    for (i = 1; i <= t; i++)
    {
        scanf("%lld", &x);

        printf("Case %lld: %lld\n", i, solve(x));
        sum = 0;
    }
}
