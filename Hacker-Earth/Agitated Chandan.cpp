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

int a,b,weight,t,n;
int dist[100005];

pair<int,int> bfs(vector<pair<int,int> >adj[],int node)
{
    memset(dist,-1,sizeof(dist));
    queue<int> Q;
    Q.push(node);
    dist[node] = 0;


    while(!Q.empty())
    {
        int idx = Q.front();
        Q.pop();

        for(int i = 0; i < adj[idx].size(); i++)
        {
            int nd = adj[idx][i].first;
            int cost = adj[idx][i].second;
            if(dist[nd] == -1)
            {
                dist[nd] = dist[idx] + cost;
                Q.push(nd);
            }
        }
    }
    int mxDist=-1,ind;
    for(int i = 1; i <= n; i++)
    {
        if(mxDist < dist[i])
        {
            mxDist = dist[i];
            ind = i;
        }
    }

    return make_pair(ind,mxDist);
}
int main()
{
    IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;

    W(t)
    {
        cin>>n;
        pair<int,int> t1,t2;

        vector<pair<int,int> > adj[100005];

        for(int i = 0; i < n-1; i++)
        {
            cin>>a>>b>>weight;
            adj[a].pb({b,weight});
            adj[b].pb({a,weight});
        }
        t1 = bfs(adj,1);
        t2 = bfs(adj,t1.first);

        if(t2.second < 100)
            cout<<0<<" "<<t2.second<<endl;
        else if(t2.second <= 1000)
            cout<<100<<" "<<t2.second<<endl;
        else if(t2.second < 10000)
            cout<<1000<<" "<<t2.second<<endl;
        else
            cout<<10000<<" "<<t2.second<<endl;

    }

    return 0;
}
