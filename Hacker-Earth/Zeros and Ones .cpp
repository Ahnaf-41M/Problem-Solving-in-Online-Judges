#include<bits/stdc++.h>
using namespace std;

int tree[4000000];
int n;
void build(int node, int b, int e)
{
	if (b == e)
	{
		tree[node] = 1;
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	build(left, b, mid);
	build(right, mid + 1, e);

	tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int ind)
{
	if (b == ind && ind == e)
	{
		tree[node] = 0;
		return;
	}
	if (ind < b || ind > e) //irrelevant segment
		return;
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	update(left, b, mid, ind);
	update(right, mid + 1, e, ind);

	tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int k)
{
	if (b < 1 || e > n || tree[node] < k)
		return -1;
	if (b == e && k == 1)
		return b;

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	int leftVal = tree[left];
	int rightVal = tree[right];

	if (k > leftVal)
		query(right, mid + 1, e, k - leftVal);
	else
		query(left, b, mid , k);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q, ind, k;
	cin >> n >> q;

	build(1, 1, n);

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 0) {
			cin >> ind;
			update(1, 1, n, ind);
		}
		else {
			cin >> k;
			cout << query(1, 1, n, k) << endl;
		}
	}


}