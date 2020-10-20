
#include<bits/stdc++.h>
using namespace std;

#define White 1
#define Grey 2
#define Black 3
int node,edge;
int parent[100],dis[100];
int color[100],adj[100][100];

void bfs(int snode)
{
    int i;
    for(i = 1; i <= node; i++)
    {
        color[i]=0;
        parent[i]=-1;
        dis[i]=INT_MIN;
    }
    dis[snode]=0;
    parent[snode]=-1;

    queue<int> q;
    q.push(snode);

    while(!q.empty())
    {
        int x;
        x = q.front();
        q.pop();
        color[x]=1;

        for(i = 1; i <= node; i++)
        {
            if(adj[x][i]==1 && color[i]==0)
            {
                dis[i]=dis[x]+1;
                parent[i]=x;
                q.push(i);
            }
        }

    }
}
int main()
{
    int i,n1,n2;
    cin>>node;

    for(i = 1; i <= node-1; i++)
    {
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    bfs(1);
    int t;
    cin>>t;
    int v[t];
    //int w[t];
    for(i = 0; i < t; i++)
    {
        cin>>v[i];
        //w[i]=dis[v[i]];
    }
    int minn=INT_MAX,minn2=INT_MAX;
    for(i = 0; i < t; i++)
    {
        if(dis[v[i]]<=minn && minn2>=v[i])
        {
            minn = dis[v[i]];
            minn2 = v[i];
        }

    }
    cout<<minn2<<endl;
}

