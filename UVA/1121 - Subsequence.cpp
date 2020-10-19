#include<bits/stdc++.h>
#define ll long long 

using namespace std;

void smallestSubWithSum(ll a[],ll n,ll m)
{
    ll cur_sum=0,min_len=n+1;
    ll start=0,end=0;

    while(end < n)
    {
        while(cur_sum < m && end < n)
          cur_sum += a[end++];
        while(cur_sum >= m && start < n)
        {
            if(end - start < min_len)
              min_len = end - start;
            cur_sum -= a[start++];
        }
    }
    if(min_len == n+1)
    cout<<0<<endl;
    else
    cout<<min_len<<endl;
}
int main()
{
    ll n,m,i;

    while (scanf("%lld%lld",&n,&m) != EOF)
    {
        ll a[n];

        for(i = 0; i < n; i++) cin>>a[i];

        smallestSubWithSum(a,n,m);
    }
    
}