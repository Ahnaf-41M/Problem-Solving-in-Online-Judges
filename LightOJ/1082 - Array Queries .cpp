#include<bits/stdc++.h>
using namespace std;

#define Max 100001
int a[Max];
int minn;
int tree[Max*3];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]= a[b];
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = min(tree[left],tree[right]);
}
int query(int node, int b, int e, int i, int j)
{

    if (i > e || j < b)
        return INT_MAX;
    if (b >= i && e <= j)
    {
        return tree[node];
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1,p2);

}

int main()
{
    int n,i,t,m,j=1,q,p,g;

    scanf("%d",&t);
    while(t--)
    {
        //printf("\n");
        scanf("%d %d",&n,&q);
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        init (1,1,n);
        printf("Case %d:\n",j);
        while(q--)
        {
            scanf("%d %d",&p,&g);
            printf("%d\n",query(1, 1, n, p, g));
        }
        j++;

    }
}


