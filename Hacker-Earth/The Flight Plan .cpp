#include<bits/stdc++.h>
using namespace std;

#define White 1
#define Grey 2
#define Black 3
int node,edge;
int adj[1005][1005];

void bfs(int snode,int parent[],int dis[],int color[])
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
               color[i]=1;
            }
        }

    }
}
int main()
{
    int i,t,c,n1,n2;
    int x,y;

    cin>>node>>edge>>t>>c;


    int parent[node+1],dis[node+1];
    int color[node+1];

    for(i = 1; i <= edge; i++)
    {
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    cin>>x>>y;

    bfs(x,parent,dis,color);

    vector<int> v;
    int temp = y;

    while(true)
    {
         if(temp==-1)
         {
              break;
         }
         v.push_back(temp);
         temp = parent[temp];
    }
    cout<<v.size()<<endl;
    for(i = v.size()-1; i >= 0; i--)
     cout<<v[i]<< " ";

    cout<<endl;


}


