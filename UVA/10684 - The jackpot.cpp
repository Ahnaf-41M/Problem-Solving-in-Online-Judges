
#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)        for(int i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    IOS
    ll n;
    while(cin>>n,n)
    {
        ll cur_mx = 0,mx_so_far = INT_MIN;

        while(n--)
        {
            ll x;
            cin>>x;
            cur_mx+=x;
            if(cur_mx > mx_so_far)
                mx_so_far = cur_mx;
            if(cur_mx < 0)
                cur_mx = 0;
        }
        if(mx_so_far <= 0)
            cout<<"Losing streak.\n";
        else
            cout<<"The maximum winning streak is "<<mx_so_far<<".\n";
    }

    return 0;
}
