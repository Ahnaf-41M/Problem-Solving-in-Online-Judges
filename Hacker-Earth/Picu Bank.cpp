#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
   ll  D, X, A, B, t, M, ans, rem;

   cin >> t;

   while (t--)
   {
      cin >> D >> A >> M >> B >> X;
      X -= D; //extract initial value

      /*As after every M months B dollars are being added.*/
      ans = X / (A * M + B);
      ans *= (M + 1);
      rem = X % (A * M + B);
      if (rem) {
         if (rem <= M * A)
            ans += ((rem + A - 1) / A);
         else
            ans += (M + 1);
      }
      cout << ans << endl;
   }
   return 0;

}

