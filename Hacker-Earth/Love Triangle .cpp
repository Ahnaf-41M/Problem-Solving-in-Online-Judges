#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findans(ll n)
{
    if(n<9)
        return n;
    else
        return n%9+10*(findans(n/9));
}

int main()
{
    ll n;

    while(scanf("%lld",&n)!=EOF)
    {
        cout<<findans(n)<<endl;
    }
}
