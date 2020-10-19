#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll n,i;

    while(scanf("%lld",&n) && n!=0)
    {
        ll sum=0,cost=0;
        ll x,y;
        if(n==2)
        {
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",x+y);
        }
        else
        {
            priority_queue<ll,vector<ll>,greater<ll> > pq;
            while(n--)
            {
                scanf("%lld",&x);
                pq.push(x);
            }


            while(pq.size() > 1)
            {
                sum = pq.top();
                pq.pop();
                sum+= pq.top();
                pq.pop();
                cost+=sum;
                pq.push(sum);
            }
            printf("%lld\n",cost);
        }
    }
}
