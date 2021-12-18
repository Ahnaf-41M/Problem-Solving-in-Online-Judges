#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  MX           100005
#define  pi           2*acos(0.0)
#define  endl         "\n"
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
#define  IOS          ios_base::sync_with_stdio(0);cin.tie(0);
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;

void Solve(int tc)
{
    int n,ans=0;
    ordered_set<int> S;

    cin >> n;

    int ar[n];
    for(int &x : ar) cin >> x;

    irep(i,n-1,0)
    {
        int x = S.order_of_key(ar[i]);
        ans+=x;
        S.insert(ar[i]);
    }
    cout << ans <<"\n";
}
signed main()
{
    IOS
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        Solve(tc);
    }
}
