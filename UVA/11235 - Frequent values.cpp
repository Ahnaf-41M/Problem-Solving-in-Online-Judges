#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      100005
#define inf     1000000
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tree[4 * MX], a[MX], rightFreq[MX], leftFreq[MX];
int n, q;

void build(int node, int b, int e)
{
	if (b == e) {
		tree[node] = leftFreq[b];
		return;
	}

	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;

	build(left, b, mid);
	build(right, mid + 1, e);

	tree[node] = max(tree[left], tree[right]);
}
int Query(int node, int b, int e, int L, int R)
{
	if (b > R || e < L) return 1;

	if (b >= L && e <= R) return tree[node];

	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;

	int p1 = Query(left, b, mid, L, R);
	int p2 = Query(right, mid + 1, e, L, R);

	return max(p1, p2);
}
int main()
{
	IOS

	while (cin >> n, n)
	{
		cin >> q;
		int i, j;

		rep(i, 1, n + 1) cin >> a[i];
		for (i = 1, j = n; i <= n, j >= 1; i++, j--) {
			if (i == 1) leftFreq[i] = 1;
			else if (a[i] == a[i - 1]) leftFreq[i] = leftFreq[i - 1] + 1;
			else leftFreq[i] = 1;

			if (j == n) rightFreq[j] = 1;
			else if (a[j] == a[j + 1]) rightFreq[j] = rightFreq[j + 1] + 1;
			else rightFreq[j] = 1;
		}
		build(1, 1, n);
		W(q)
		{
			int l, r; cin >> l >> r;

			if (a[l] == a[r]) cout << r - l + 1 << endl;
			else
			{
				int r1 = rightFreq[l];
				int r2 = Query(1, 1, n, r1 + l, r);

				cout << max(r1, r2) << endl;
			}
		}
	}
}