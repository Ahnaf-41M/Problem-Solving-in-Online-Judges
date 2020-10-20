#include<bits/stdc++.h>
using namespace std;

#define Max 100000
#define mx 1000000
int a[Max];
int tree[Max*3];
int prime[mx];
void sieve()
{
    int i,j;
    prime[2]=1;
    for(i = 3; i <= mx; i+=2)
        prime[i]=1;
    for(i = 2; i <= sqrt(mx); i++)
    {
        if(prime[i]==1)
        {
            for(j = 2; i*j <= mx; j++)
            {
                prime[i*j]=0;
            }
        }
    }


}

void init(int node, int b, int e)
{
    sieve();
    if(b==e)
    {
        tree[node]= prime[a[b]];
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]+= tree[left]+tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int ind,int nv)
{
    if(ind>e || ind<b)
    {
        return;
    }

    if(b>=ind && e<=ind)
    {
        tree[node]=prime[nv];
        return ;
    }
    int left= 2*node;
    int right = 2*node+1;
    int mid=(b+e)/2;

    update(left,b,mid,ind,nv);
    update(right,mid+1,e,ind,nv);
    tree[node]= tree[left]+tree[right];

}
int main()
{
    int n,i,q,ind,nv,p,x,r1;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    init (1,1,n);
    cin>>x;
    while(x--)
    {
        cin>>r1>>p>>q;
        if(r1==2)
            update(1,1,n,p,q);

        else
            cout<<query(1, 1, n, p, q) << endl;
    }

}

