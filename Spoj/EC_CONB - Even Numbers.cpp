/*#include<bits/stdc++.h>

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define ll long long
#define pb push_back
#define PI M_PI
#define endl "\n"
#define sc scanf
#define pf printf
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
     IOS
     bitset<25> bt;
     int a=1e7;
     bt = a;
     //unsigned long b = bt.to_ulong();
     string s = bt.to_string();
     //cout<<s;
     cout<<bt<<' '<<s<<endl;
     reverse(s.begin(),s.end());
     bitset<25> bb(s);
     cout<<bb;
     return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ul unsigned long

int main()
{
     IOS
     ul t,x;
     cin>>t;

     while(t--)
     {
          cin>>x;
          if(x&1)
          {
               cout<<x<<endl;
          }
          else
          {
               bitset<sizeof(x)> bt1 = x;
               string s = bt1.to_string();
               reverse(s.begin(),s.end());
               bitset<25> bt2(s);
               cout<<bt2<<endl;
               x = bt2.to_ulong();
               cout<<x<<endl;
          }
     }
}
