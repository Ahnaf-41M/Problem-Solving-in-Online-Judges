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

int divSum[MX];
void Work()
{
    for (int i = 1; i < MX; i++)
        for (int j = 2 * i; j < MX; j += i)
            divSum[j] += i;
}
void Solve(int tc)
{
    int x, y;
    cin >> x >> y;
    if (divSum[x] == y && divSum[y] == x) cout << "Friendship is ideal\n";
    else cout << "Friendship is not ideal\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Work();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}