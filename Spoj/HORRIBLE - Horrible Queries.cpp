#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 100005
ll a[Max];

struct info
{
    ll prop, sum;
} tree[Max * 4];

void update(ll node, ll b, ll e, ll p, ll q, ll x)
{
    if (q < b || p > e)
        return;

    if (b >= p && e <= q)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, p, q, x);
    update(right, mid + 1, e, p, q, x);
    
    tree[node].sum = tree[left].sum + tree[right].sum + (tree[node].prop) * (e - b + 1);
}
ll query(ll node, ll b, ll e, ll f, ll d, ll carry = 0)
{
    if (f > e || d < b)
        return 0;

    if (b >= f && e <= d)
        return tree[node].sum + carry * (e - b + 1);

    ll left = 2 * node;
    ll right = 2 * node + 1;
    ll mid = (b + e) / 2;

    ll p1 = query(left, b, mid, f, d, carry + tree[node].prop);
    ll p2 = query(right, mid + 1, e, f, d, carry + tree[node].prop);

    return p1 + p2;
}
int main()
{
    ll n, i, p, q, x, d, f, t, g, h, h1, h2, h3;

    scanf("%lld", &t);

    while (t--)
    {
        scanf("%lld %lld", &n, &g);
        memset(a, 0, sizeof(a));
        memset(tree, 0, sizeof(tree));

        while (g--)
        {
            scanf("%lld", &h);
            if (h == 0)
            {
                scanf("%lld %lld %lld", &h1, &h2, &h3);
                update(1, 1, n, h1, h2, h3);
            }
            else
            {
                scanf("%lld %lld", &p, &q);
                printf("%lld\n", query(1, 1, n, p, q, 0));
            }
        }

    }


}
