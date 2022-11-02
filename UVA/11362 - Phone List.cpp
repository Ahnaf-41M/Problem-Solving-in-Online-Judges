#include <bits/stdc++.h>
using namespace std;
#define K 10

struct Node
{
    Node *next[K];
    bool isEnd = false;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    Node *getNode()
    {
        return new Node();
    }
    void Insert(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - '0';
            if (cur->next[val] == NULL)
            {
                cur->next[val] = getNode();
            }
            cur = cur->next[val];
        }
        cur->isEnd = true;
    }

    bool isPrefix(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - '0';
            if (cur->next[val] == NULL)
            {
                return false;
            }
            cur = cur->next[val];
        }
        bool ok = 0;
        for (int i = 0; i < 10; i++)
        {
            if (cur->next[i] != NULL)
            {
                ok = 1;
                break;
            }
        }
        return ok;
    }
};
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        Trie T;
        map<string, int> cnt;
        int n, ok = 1;

        cin >> n;
        vector<string> v(n);

        for (string &s : v)
        {
            cin >> s;
            T.Insert(s);
            cnt[s]++;
        }
        for (string s : v)
        {
            if (cnt[s] > 1 || T.isPrefix(s))
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
