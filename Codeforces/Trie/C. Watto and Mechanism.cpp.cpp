<<<<<<< HEAD
#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

struct Node
{
	Node *next[3];
	int isEnd = 0;
};

class Trie {
public:
	string s;
	int len;
	Node *root;
	Trie() {
		root = new Node();
	}
	Node *getNode() {
		return new Node();
	}
	void insert() {
		Node *cur = root;
		for (char ch : s) {
			int val = ch - 'a';
			if (cur->next[val] == NULL)
				cur->next[val] = getNode();
			cur = cur->next[val];
		}
		cur->isEnd = 1;
	}
	bool dfs(Node *cur, int cnt, int pos) {
		bool res = 0;
		if (cnt > 1) return 0;
		if (pos >= len) {
			return (cnt == 1 && cur->isEnd == 1);
		}
		for (int i = 0; i < 3; i++) {
			if (cur->next[i] == NULL) continue;
			if (s[pos] != (i + 'a'))
				res |= dfs(cur->next[i], cnt + 1, pos + 1);
			else
				res |= dfs(cur->next[i], cnt, pos + 1);
		}
		return res;
	}

};
void Solve(int tc)
{
	Trie T;
	int n, m;

	cin >> n >> m;
	while (n-- > 0) {
		cin >> T.s;
		T.insert();
	}
	while (m-- > 0) {
		cin >> T.s;
		T.len = T.s.size();
		if (T.dfs(T.root, 0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
=======
#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

struct Node
{
	Node *next[3];
	int isEnd = 0;
};

class Trie {
public:
	string s;
	int len;
	Node *root;
	Trie() {
		root = new Node();
	}
	Node *getNode() {
		return new Node();
	}
	void insert() {
		Node *cur = root;
		for (char ch : s) {
			int val = ch - 'a';
			if (cur->next[val] == NULL)
				cur->next[val] = getNode();
			cur = cur->next[val];
		}
		cur->isEnd = 1;
	}
	bool dfs(Node *cur, int cnt, int pos) {
		bool res = 0;
		if (cnt > 1) return 0;
		if (pos >= len) {
			return (cnt == 1 && cur->isEnd == 1);
		}
		for (int i = 0; i < 3; i++) {
			if (cur->next[i] == NULL) continue;
			if (s[pos] != (i + 'a'))
				res |= dfs(cur->next[i], cnt + 1, pos + 1);
			else
				res |= dfs(cur->next[i], cnt, pos + 1);
		}
		return res;
	}

};
void Solve(int tc)
{
	Trie T;
	int n, m;

	cin >> n >> m;
	while (n-- > 0) {
		cin >> T.s;
		T.insert();
	}
	while (m-- > 0) {
		cin >> T.s;
		T.len = T.s.size();
		if (T.dfs(T.root, 0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
>>>>>>> 1a484e7541c65f0a86b1bbedf028ecc4e01130eb
}