#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      1000005
#define inf     1000000
#define mod     1000000007
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

bool is_prime[MX + 6];
vector<int> prime;

inline void sieve()
{
   for (int i = 3; i <= MX; i += 2)
      is_prime[i] = true;
   for (int i = 3; i <= sqrt(MX); i += 2)
      if (is_prime[i])
         for (int j = i * 2; j <= MX; j += i)
            is_prime[j] = false;
   prime.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (is_prime[i])
         prime.pb(i);
}
int main()
{
   IOS
   sieve();

   int n, i, x;
   map<int, int> solve;

   cin >> n;

   W(n)
   {
      cin >> x;

      if (x == 1)
         solve[1]++;
      else if (is_prime[x])
         solve[2]++;
      else if (floor(sqrt(x)) == ceil(sqrt(x)) && is_prime[(int)sqrt(x)])
         solve[3]++;
      else
      {
         int ans = 1;
         i = 0;
         while (prime[i] * prime[i] <= x)
         {
            int cnt = 0;
            while (x % prime[i] == 0)
            {
               cnt++;
               x /= prime[i];
               if (cnt > 4)
                  break;
            }
            ans *= (cnt + 1);
            if (ans > 4)
               break;
            i++;
         }
         if (x > 1)
            ans *= 2;
         solve[ans]++;
      }
   }
   cout << solve[2] + solve[3] - solve[4] - solve[1] << endl;
   // cout << solve[2] <<" "<< solve[3] <<" "<< solve[1] <<" "<< solve[4] << endl;
}