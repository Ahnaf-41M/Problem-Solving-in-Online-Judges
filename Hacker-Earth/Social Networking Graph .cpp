#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define White 1
#define Grey 2
#define Black 3
ll node,edge;
ll parent[100];


int main()
{
    ll i,n1,n2,t,a,b;

    cin>>node>>edge;
    vector<ll> adj[node+1];
    //ll color[node];

    for(i = 0; i < edge; i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    cin>>t;
   ll ans=0;
    while(t--)
    {
        cin>>a>>b;
        ll x;
        ll dis[node+1];
        memset(dis,-1,sizeof(dis));
        ans=0;

        dis[a]=0;
        queue<ll> q;
        q.push(a);

        while(!q.empty())
        {
             x;
            x = q.front();
            q.pop();

            for(i = 0; i < adj[x].size(); i++)
            {
                if(dis[adj[x][i]]==-1)
                {
                    dis[adj[x][i]]=dis[x]+1;

                    if(dis[adj[x][i]]==b)
                    {
                        ans++;
                    }
                    q.push(adj[x][i]);
                }
            }

        }
        cout<<ans<<endl;

    }


}


