#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int ans[12][12];

int SOD2(int x)
{
   int res = 0;
   while (x)
      res += x % 10, x /= 10;
   return res;
}
int SOD(int n)
{
   int sum = SOD2(n);
   while (sum >= 10)
      sum = SOD2(sum);
   return sum;
}
int SOD3(string s)
{
   int res = 0;
   for (char ch : s) {
      int dig = ch - 48;
      res += dig;
   }
   res = SOD(res);
   return res;
}
void Work()
{
   for (int i = 1; i <= 9; i++) {
      int cur = i;
      ans[i][0] = 1;
      for (int j = 1; j <= 6; j++) {
         ans[i][j] = SOD(cur);
         cur *= i;
      }
   }
}
int Rem(string s, int x)
{
   int mod = 0;

   for (char ch : s) {
      int digit = ch - '0';
      mod = mod * 10 + digit;
      mod %= x;
   }
   return mod;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   Work();

   int t; cin >> t;

   for (int k = 1; k <= t; k++) {
      string a, b;
      cin >> a >> b;

      int a1 = SOD3(a), b1;
      if (b.size() == 1 && b[0] == '0') //b is zero
         b1 = 0;
      else {
         if (a1 % 3 == 0) {
            b1 = 1;
            if (b.size() > 1 || b[0] >= '2')
               b1 = 2;
         }
         else {
            if (a1 == 2 || a1 == 5) {
               b1 = Rem(b, 6);
               if (!b1 && (b.size() > 1 || b[0] >= '6'))
                  b1 = 6;
            }
            else if (a1 == 4 || a1 == 7) {
               b1 = Rem(b, 3);
               if (!b1 && (b.size() > 1 || b[0] >= '3'))
                  b1 = 3;
            }
            else if (a1 == 8) {
               b1 = Rem(b, 2);
               if (!b1 && (b.size() > 1 || b[0] > '1'))
                  b1 = 2;
            }
         }
      }

      cout << "Case " << k << ": " << ans[a1][b1] << "\n";
   }

   return 0;
}