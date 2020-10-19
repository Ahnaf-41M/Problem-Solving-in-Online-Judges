#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ll t, i;

   scanf("%lld",&t);

   rep(i, 1, t + 1)
   {
      ll n;
      string name;
      cin >> n >> name;
      printf("Case %lld: ",i);
      n %= 3ll;
      if (name == "Alice") {
         if (n == 0 || n == 2) cout << "Alice\n";
         else cout << "Bob\n";
      }
      else {
         if (n == 1 || n == 2) cout << "Bob\n";
         else cout << "Alice\n";
      }

   }

   return 0;
}