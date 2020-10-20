#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;

int cost[11000];
void bfs(vector<int> v[])
{
    queue<int>q;
    q.push(1);
    cost[1]=0;
    while(!q.empty())
    {
        int idx=q.front();

        q.pop();
        for(int i=0; i<v[idx].size(); i++)
        {
            if(cost[v[idx][i]]==-1)
            {
                q.push(v[idx][i]);
                cost[v[idx][i]]=cost[idx]+1;

            }
        }
    }
    cout<<cost[n]<<endl;
}

int main()
{
    cin>>t;
    while(t--)
    {

        memset(cost,-1,sizeof cost);

        scanf("%d%d",&n,&m);
        vector<int>v[100005];
        for(int i=0; i<m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs(v);
        v[100005].clear();

    }

}
