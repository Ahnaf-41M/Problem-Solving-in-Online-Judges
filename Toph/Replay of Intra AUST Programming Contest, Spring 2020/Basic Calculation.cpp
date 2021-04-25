#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

int MOD = 1e9 + 7;

int Cal(string s)
{
   int base = 0, num = 0;
   for (char x : s) {
      int dig = x - '0';
      num = num * 10 + dig;
      num %= MOD;
   }
   return num;
}
void Solve(int k)
{
   string s, s1 = "", s2 = "";
   int a = 0, b = 0, t = 1;
   char op = 'a';
   cin >> s;

   for (char x : s) {
      if (x == '+' || x == '*' || x == '-') {
         // cout << s1 << endl;
         if (op != 'a') {
            if (op == '+')
               a = ( a % MOD + Cal(s1) % MOD) % MOD;
            else if (op == '*')
               a = ( a % MOD * Cal(s1) % MOD) % MOD;
            else
               a = ( a % MOD - Cal(s1) % MOD) % MOD;
            b = 0;
         }
         else a = Cal(s1);
         op = x;
         s1 = "";
      }
      else
         s1 += x;
   }
   // cout << s1<<endl;
   if (op != 'a') {
      if (op == '+')
         a = ( a % MOD + Cal(s1) % MOD) % MOD;
      else if (op == '*')
         a = ( a % MOD * Cal(s1) % MOD) % MOD;
      else
         a = ( a % MOD - Cal(s1) % MOD) % MOD;
      b = 0;
   }
   else a = Cal(s1);
   // a%=MOD;
   if (a < 0) {
      a = MOD + (a % MOD);
   }
   cout << "case #" << k << ": " << a << endl;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;

   for (int k = 1; k <= T; k++) {
      Solve(k);
   }

   return 0;
}