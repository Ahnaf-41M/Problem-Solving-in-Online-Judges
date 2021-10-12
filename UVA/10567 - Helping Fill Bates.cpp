#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

vector<vector<int> > v;
string s;
int q;

void Solve(int tc)
{
   v.resize(200);

   cin >> s >> q;
   rep(i, 0, (int)s.size() - 1) v[s[i]].pb(i);

   while (q--) {
      string ss;
      bool ok = 1;
      int last = -1, first;

      cin >> ss;

      rep(i, 0, (int)ss.size() - 1) {
         char ch = ss[i];
         int ub = upper_bound(all(v[ch]), last) - v[ch].begin(); //finding the next index of the current character greater than 'last'
         if (ub == v[ch].size()) ok = 0; //if there is no index exist greater than 'last'
         if (i == 0) first = v[ch][ub];
         last = v[ch][ub];
      }
      if (ok) cout << "Matched " << first << " " << last << "\n";
      else cout << "Not matched\n";
   }
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}