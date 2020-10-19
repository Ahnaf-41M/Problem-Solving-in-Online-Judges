#include<bits/stdc++.h>
#include <ext/rope>

#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))

#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)    __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)       __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)       __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define PI   M_PI
#define endl "\n"
#define sc   scanf
#define pf   printf

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep1(i,n)       for(int i = 0; i < n; i++)
#define rep2(a,b)       for(int i = a; i <= b; i++)
#define rep3(a,b,c)     for(int i = a; i <= b; i+=c)
#define irep(a,b,c)     for(int i = b; i >=a; i-=c)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_cxx;

void DFS(int nd,vector<int> adj[],bool vis[])
{
    vis[nd] = true;

    for(auto it : adj[nd])
        if(!vis[it])
            DFS(it,adj,vis);
}
int main()
{
    //IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d ",&t);

    char ch[2];

    while(t--)
    {
        gets(ch);

        int n = ch[0] - 64;
        vector<int> adj[10005];
        bool vis[50] = {};

        char edges[10];
        while(gets(edges))
        {
            if(edges[0]=='\0')
                break;
            int x = edges[0] - 64;
            int y = edges[1] - 64;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                DFS(i, adj, vis);
                ans++;
            }
        }
        cout<<ans<<endl;
        if(t)
            cout<<endl;

    }

    return 0;
}
