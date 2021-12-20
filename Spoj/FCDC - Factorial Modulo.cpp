
#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           10000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int a, b, Rb;
int nxt[MX],fa[MX],fb[MX];
vector<int> v,va,vb;

bool Can(int n,int *mp,vector<int> &vv)
{
    for(int d : vv)
    {
        int m = n,p=0;
        while(m)
        {
            p += (m / d);
            m /= d;
        }
        if(mp[d] > p) return false;
    }
    return true;
}
void Fact(int n,int *mp,vector<int> &vv)
{
    for(int d : v)
    {
        if(d*d > n) break;
        while(n % d == 0)
            n/=d, mp[d]++;
        if(mp[d]) vv.pb(d);
    }
    if(n > 1) mp[n]++, vv.pb(n);
}
int BSearch(int r,int *mp,vector<int> &vv)
{
    int lo = 1, hi = r,ans=-1;
    while(lo <= hi)
    {
        int mid = (lo+hi) >> 1;
        if(Can(mid,mp,vv))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}
void Sieve()
{
    for (int i = 3; i < MX; i+=2) nxt[i] = 1;
    for (int i = 3; i < MX; i+=2)
        if (nxt[i])
            for (int j = i * i; j < MX; j += i)
                nxt[j] = 0;
    v.pb(2);
    for(int i = 3; i < MX; i+=2)
        if(nxt[i])
            v.pb(i);
}
void Solve(int tc)
{
    cin >> a >> b;
    if(a>=b) cout << "0\n";
    else
    {
        Fact(a,fa,va);
        Fact(b,fb,vb);
        Rb = BSearch(b,fb,vb);
        //cout << Rb <<"\n";

        int Ra = BSearch(Rb-1, fa,va);
        if(Ra == -1) cout <<"0\n";
        else cout <<Rb - Ra<< "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
    //cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        Solve(tc);
    }

    return 0;
}
