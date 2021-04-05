#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   map<int, int> mp;
   int n;

   mp[1] = mp[64] =  mp[729] =  mp[15625] = mp[4096] = 1;
   mp[46656] = mp[117649] = mp[262144] = mp[531441] = 1;
   mp[1000000] = mp[1771561] = mp[2985984] = 1;
   mp[4826809] = mp[7529536] = mp[11390625] = 1;
   mp[16777216] = mp[24137569] = mp[34012224] = 1;
   mp[47045881] = mp[64000000] = mp[85766121] = 1;

   while (cin >> n && n) {
      cout << (mp[n] ? "Special\n" : "Ordinary\n");
   }
   return 0;
}