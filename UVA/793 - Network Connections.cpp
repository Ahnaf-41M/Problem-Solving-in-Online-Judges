#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 200005

int par[mx], n, m;

int find(int v)
{
    if (par[v] < 0)
        return v;
    else
        return par[v] = find(par[v]);
}
void Union(int x, int y)
{
    int a = find(x);
    int b = find(y);

    if (a == b) return;

    par[a] = b;
}
int main()
{
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t;

    W(t)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            par[i] = -1;
        string ch;
        int yes = 0, no = 0;
        cin.ignore();

        while (getline(cin, ch))
        {
            if (ch.empty())
                break;
            else
            {
                int x , y;
                stringstream ss(ch);
                char tmp;
                ss >> tmp;
                ss >> x; ss >> y;

                if (ch[0] == 'c')
                    Union(x, y);
                else
                {
                    int f1 = find(x);
                    int f2 = find(y);

                    if (f1 == f2)
                        yes++;
                    else
                        no++;
                }
            }
        }
        cout << yes << "," << no << endl;
        if (t) cout << endl;
    }

    return 0;
}