#include "bits/stdc++.h"
#define  MX         100005
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  int        long long
#define  PII        pair<int,int>
#define  all(v)     v.begin(),v.end()
#define  rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

vector<int> ans;
int ar[MX], tail[MX], Prev[MX];
int n;

int LowerBound(int tail[], int val, int l, int r)
{
   int ind;
   while (l <= r) {
      int mid = (l + r) >> 1;
      if (ar[tail[mid]] >= val) r = mid - 1, ind = mid;
      else l = mid + 1;
   }
   return ind;
}
void LIS()
{
   int len = 1;

   rep(i, 1, n - 1) {
      if (ar[tail[0]] > ar[i])
         tail[0] = i;
      else if (ar[tail[len - 1]] < ar[i]) {
         Prev[i] = tail[len - 1];
         tail[len++] = i;
      }
      else {
         int pos = LowerBound(tail, ar[i], 0, len - 1);
         Prev[i] = tail[pos - 1];
         tail[pos] = i;
      }
   }
   for (int i = tail[len - 1]; i >= 0; i = Prev[i])
      ans.pb(ar[i]);

   reverse(all(ans));

   printf("%lld\n-\n", len);
   for (int x : ans) printf("%lld\n", x);
}
signed main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   memset(Prev, -1, sizeof(Prev));
   memset(tail, 0, sizeof(tail));
   int j = 0;
   while (scanf("%lld", &ar[j++]) == 1)

      n = j;
   LIS();
   return 0;
}