/*For a givem n, we need to represent it in it's prime factors.
  n = 2^a * 3^b * 5^c. The number of ordered pairs will be
  (2*a+1) * (2*b+1) * (2*c+1).
  Hence our answer will be = ((2*a+1) * (2*b+1) * (2*c+1)) + 1 / 2.(as we want
  unordered pairs).Ordered pairs means, (4, 18) and (18, 4) are considered
  to be different pairs. */
#include<bits/stdc++.h>
#define  MX      10000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int unq;
bitset < MX + 5 > OK;
vector<int> primes;

void Sieve()
{
  for (int i = 3; i <= MX; i += 2)
    OK[i] = 1;
  for (int i = 3; i * i <= MX; i += 2)
    if (OK[i])
      for (int j = i * i; j <= MX; j += i)
        OK[j] = 0;
  primes.pb(2);
  for (int i = 3; i <= MX; i += 2)
    if (OK[i])
      primes.pb(i);
}
int NOD(int n)
{
  int res = 1;

  for (int x : primes) {
    if (x * x > n)
      break;
    int cnt = 0;
    while (n % x == 0)
      cnt++, n /= x;
    res *= (2 * cnt + 1);
  }
  if (n > 1)
    res *= 3;

  return res;
}
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  Sieve();
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++) {
    int n;
    cin >> n;
    int ans = NOD(n);
    ans = (ans + 1) / 2;
    cout << "Case " << k << ": " << ans << endl;
    unq = 0;
  }

  return 0;
}