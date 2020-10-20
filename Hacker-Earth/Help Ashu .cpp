#include<bits/stdc++.h>
using namespace std;

#define Max 100005
int a[Max];
pair<int,int> tree[Max*3];

void init(int node, int b, int e)
{
    if(b==e)
    {
        if(a[b]%2 == 1)
            tree[node] = {1, 0};
        else
            tree[node] = {0, 1};

        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].first= tree[left].first+tree[right].first; //for odd
    tree[node].second= tree[left].second+tree[right].second; //for even
}
int getEven(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) /*if out of the range then return 0 ..*/
        return 0;
    if (b >= i && e <= j)
        return tree[node].second;

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = getEven(Left, b, mid, i, j);
    int p2 = getEven(Right, mid + 1, e, i, j);

    return p1 + p2;
}
int getOdd(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) /*if out of the range then return 0 ..*/
        return 0;
    if (b >= i && e <= j)
        return tree[node].first;

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = getOdd(Left, b, mid, i, j);
    int p2 = getOdd(Right, mid + 1, e, i, j);

    return p1 + p2;
}
void update(int node, int b, int e, int ind,int newValue)
{
    if(ind>e || ind<b)
        return;

    if(b>=ind && e<=ind)
    {
        /* if the new values parity was different change the nodes parity */
        if(a[b]%2 == 1)
            tree[node] = {0, 1};
        else
            tree[node] = {1, 0};

        a[b] = newValue;
        return ;
    }
    int left= 2*node;
    int right = 2*node+1;
    int mid=(b+e)/2;

    update(left,b,mid,ind,newValue);
    update(right,mid+1,e,ind,newValue);

    tree[node].first= tree[left].first+tree[right].first;
    tree[node].second= tree[left].second+tree[right].second;
}
int main()
{
    int n,i,x,y,q,check;

    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    init (1,1,n);
    cin>>q;

    while(q--)
    {
        cin>>check>>x>>y;
        if(check == 0)
        {
            if((a[x]%2) == (y%2)) //if the new value has same parity as the old value at index x
                continue;
            else
                update(1,1,n,x,y);
        }
        else if(check == 1)
            cout<<getEven(1,1,n,x,y)<<endl;
        else
            cout<<getOdd(1,1,n,x,y)<<endl;

    }

}


