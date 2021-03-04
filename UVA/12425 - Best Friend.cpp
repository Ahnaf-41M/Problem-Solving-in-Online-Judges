#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            1000005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

map<int, int> pre_sum;

int Totient(int N)
{
   int res = N;

   if (N % 2 == 0) {
      res -= res / 2;
      while (N % 2 == 0)
         N /= 2;
   }

   for (int i = 3; i * i <= N; i += 2) {
      if (N % i == 0) {
         res -= res / i;
         while (N % i == 0)
            N /= i;
      }
   }
   if (N > 1)
      res -= res / N;
   return res;
}
void Pre_Cal(int N)
{
   for (int i = 1; i * i <= N; i++) {
      if (i == 1) {
         pre_sum[i] += Totient(N / i);
         pre_sum[N] += 1;
      }
      else if (N % i == 0) {
         int d1 = i;
         int d2 = N / i;

         if (d1 == d2)
            pre_sum[d1] += Totient(N / d1);
         else {
            pre_sum[d1] += Totient(N / d1);
            pre_sum[d2] += Totient(N / d2);
         }
      }
   }

   for (auto it = pre_sum.begin(); it != pre_sum.end(); it++) {
      auto it2 = it;
      it2++;
      if (it2 != pre_sum.end()) {
         pre_sum[it2->first] += it->second;
      }
   }
}
void Solve()
{
   int N, Q;

   cin >> N >> Q;

   Pre_Cal(N);

   while (Q--) {
      int x; cin >> x;
      auto it = pre_sum.lower_bound(x);
      if (x <= 0)
         cout << 0 << endl;
      else if (it == pre_sum.end()) {
         it--;
         cout << (*it).second << endl;
      }
      else {
         if ((*it).first > x)
            it--;
         cout << (*it).second << endl;
      }
   }
   // for (auto it : pre_sum)
   //    cout << it.first << " " << it.second << endl;
   pre_sum.clear();
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;

   rep(k, 1, T) {
      cout << "Case " << k << endl;
      Solve();
   }

   return 0;
}