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

bool visited[100006];
int level[100006];
int n,x;
vector<int> adj[100006];

void BFS(int nd)
{
     visited[nd] = true;
     level[nd] = 0;
     queue<int> Q;

     Q.push(nd);

     while(!Q.empty())
     {
          int idx = Q.front();
          Q.pop();

          for(int i = 0; i < adj[idx].size(); i++)
          {
               int node = adj[idx][i];
               if(!visited[node])
               {
                    level[node] = level[idx] + 1;
                    Q.push(node);
                    visited[node] = true;
               }
          }
     }
     int ans=0;
     for(int i = 1; i <= n; i++)
     {
          if(level[i] == x-1)
               ans++;
     }
     cout<<ans<<endl;
}
int main()
{
     IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>n;

    for(int i = 0; i < n-1; i++)
    {
         int a,b;
         cin>>a>>b;
         adj[a].pb(b);
         adj[b].pb(a);
    }
    cin>>x;
    BFS(1);

     return 0;
}

