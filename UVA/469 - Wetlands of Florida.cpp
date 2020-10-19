#include<bits/stdc++.h>
#include <ext/rope>

#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))

#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)    __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)       __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)       __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define PI   M_PI
#define endl "\n"
#define sc   scanf
#define pf   printf

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep1(i,n)       for(int i = 0; i < n; i++)
#define rep2(a,b)       for(int i = a; i <= b; i++)
#define rep3(a,b,c)     for(int i = a; i <= b; i+=c)
#define irep(a,b,c)     for(int i = b; i >=a; i-=c)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_cxx;

bool visited[120][120];
char mp[120][120];
int cnt;
void DFS(int a, int b)
{
    if (a < 0 || b < 0 || visited[a][b])
        return;
    if (mp[a][b] != 'W' || mp[a][b] == 0)
        return;

    cnt++;
    visited[a][b] = true;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            DFS(a + i, b + j);
}
int main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("ouput.txt","w",stdout);

    int t, i;

    scanf("%d ", &t);

    W(t)
    {
        char s2[110];
        int j;
        i=0;
        memset(mp, 0, sizeof(mp));

        while (gets(s2))
        {
            if (s2[0] == '\0')
                break;
            if (s2[0] != 'W' && s2[0] != 'L')
            {
                int x, y;
                cnt = 0;

                memset(visited, false, sizeof(visited));
                sscanf(s2, "%d %d", &x, &y);

                DFS(x - 1, y - 1);
                cout << cnt << endl;

            }
            else
            {
                sscanf(s2, "%s", mp[i]);
                i++;
            }
        }
        if (t)
            cout << endl;

    }

    return 0;
}

