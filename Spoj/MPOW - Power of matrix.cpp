#include<bits/stdc++.h>
using namespace std;
#define N   201
#define ll  long long
#define mod 1000000007

ll A[N][N], Identity[N][N];

void multiply(ll I[][N], ll ar[][N], ll dim)
{
   //normal matrix multiplication
   ll res[dim + 1][dim + 1] = {};
   for (ll i = 1; i <= dim; i++)
      for (ll j = 1; j <= dim; j++)
         for (ll k = 1; k <= dim; k++)
            res[i][j] = (res[i][j]+(I[i][k] * ar[k][j])) % mod;

   for (ll i = 1; i <= dim; i++)
      for (ll j = 1; j <= dim; j++)
         I[i][j] = res[i][j];
}
void Power(ll ar[][N], ll dim, ll n)
{
   for (ll i = 1; i <= dim; i++) {
      for (ll j = 1; j <= dim; j++) {
         if (i == j)
            Identity[i][j] = 1;
         else
            Identity[i][j] = 0;
      }
   }

   //Using Binary Exponetiation for multiplying array n times
   while (n)
   {
      if (n & 1)
         multiply(Identity, ar, dim), n--;
      else
         multiply(ar, ar, dim), n /= 2;
   }

   for (ll i = 1; i <= dim; i++)
      for (ll j = 1; j <= dim; j++)
         ar[i][j] = Identity[i][j] % mod;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //for calculation (A[][])^n
   ll n, dim, t;

   cin >> t;

   while (t--)
   {
      cin >> dim >> n;
      memset(Identity, 0, sizeof(Identity));
      memset(A, 0, sizeof(A));

      for (ll i = 1; i <= dim; i++)
         for (ll j = 1; j <= dim; j++)
            cin >> A[i][j];

      Power(A, dim, n);

      for (ll i = 1; i <= dim; i++) {
         for (ll j = 1; j <= dim; j++) {
            cout << A[i][j] << " ";
         }
         cout << endl;
      }
   }

}