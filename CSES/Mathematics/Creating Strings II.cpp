/*As we have to find out fact[n]/fact[freq['a']]*...*fact[freq['z']]
 (n = string size) and we know that a^-1 = a^(mod-2) % mod where
 mod is a prime number. Using the formula we are going to 
 pre-calculate every inverse of factorials till 1000000. 
 Ans = fact[n] * Inverse[fact[freq['a']]]*...*Inverse[fact[freq['z']]] % mod.*/

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

const int mod = 1e9 + 7;
int freq[150];
int fact[MX + 5], Inverse[MX + 5];

int BigMod(int a, int n)
{
   int res = 1;
   while (n) {
      if (n & 1)
         res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
   }
   return res;
}
void Pre_Cal()
{
   Inverse[0] = Inverse[1] = fact[0] = fact[1] = 1;
   rep(i, 2, MX) {
      fact[i] = fact[i - 1] * i % mod;
      Inverse[i] = BigMod(fact[i], mod - 2);
   }
}
void Solve()
{
   Pre_Cal();
   string s;
   int n, ans = 1;

   cin >> s;

   n = s.size();
   ans = fact[n];

   rep(i, 0, n - 1) freq[s[i]]++;

   for (char ch = 'a'; ch <= 'z'; ch++) {
      int cur = freq[ch];
      ans = ans * Inverse[cur] % mod;
   }
   cout << ans;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   //int T;
   //cin >> T;

   //while (T--)
   Solve();

   return 0;
}